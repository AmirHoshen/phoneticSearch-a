//
// Created by miros on 20/03/2020.
//
/**
 * Phonetic search method definition:
 * this method will get both a sentence and a word (represented by string)
 * @param sentence - a misspelled sentence .
 * @param word - the word we are looking for in the sentence.
 * the letters that may have been replaced mistakenly:
 * v,w
 * b,f,p
 * g,j
 * c,k,q
 * s,z
 * d,t
 * o,u
 * i,y
 */
#include <string>
#include <stdexcept>
#include <bits/stdc++.h>
#include <iostream>


#include"PhoneticFinder.hpp"

using namespace std;

/**
 * method will find a match similarity of a word in an misspelled sentence as defined(ABOVE).
 * @param sentence - the (could be) misspelled sentence.
 * @param word - the word we are looking for in the sentence.
 * @return the word as represented in the sentence.
 */
std::string phonetic::find(std::string sentence, std::string word) {

    if (word == "") {
        throw out_of_range{"ERROR: inserted an empty word."
        };
    }

    string tmpWord = word;
    string tmp1;
    string tmp2;
    int count = 0;
    //lower case the word.
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    //adding to tmp1 word from the sentence.
    for (int i = 0; i < sentence.length(); ++i) {
        if (sentence[i] != ' ') {
            tmp1.append(1u, sentence[i]);
        }
        if (sentence[i] == ' ' || i == sentence.length() - 1) {
            if (tmp1.length() == word.length()) {
                tmp2 = tmp1;
                transform(tmp1.begin(), tmp1.end(), tmp1.begin(), ::tolower);
                for (int i = 0; i < word.length(); ++i) {
                    count += similarChar(tmp1[i], word[i]);
                }
                if (count == word.length()) {
                    return tmp2;
                }

            }
            tmp1.clear();
            count = 0;
        }
    }
    throw out_of_range{tmpWord + " not found in the text"};
}


//return the number 1 for legal sequence.
/**
 * finding similarities between a char from the same index of sentence and word.
 * @param a char from the sentence.
 * @param b  char from the word.
 * @return 1- if it is a similarity pattern as defined
 *         0- otherwise.
 */
int similarChar(char a, char b){
    if((b=='w' || b=='v') && (a=='w' || a=='v'))
        return 1;
    if((b=='g' || b=='j') && (a=='g' || a=='j'))
        return 1;
    if((b=='s' || b=='z') && (a=='s' || a=='z'))
        return 1;
    if((b=='t' || b=='d') && (a=='t' || a=='d'))
        return 1;
    if((b=='o' || b=='u') && (a=='o' || a=='u' ))
        return 1;
    if((b=='i' || b=='y') && (a=='i' || a=='y'))
        return 1;
    if((b=='b' || b=='f' || b=='p') && (a=='b' || a=='f' || a=='p'))
        return 1;
    if((b=='c' || b=='k' || b=='q') && (a=='c' || a=='k' || a=='q'))
        return 1;
    if(a==b) return 1;
    return 0;
}

