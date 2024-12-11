#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

WordCount wordCountArray[MAX_WORDS];
int numWords = 0;
int findWordIndex(char* word) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(wordCountArray[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}
void addOrIncrementWord(char* word) {
    int idx = findWordIndex(word);
    if (idx == -1) {
        if (numWords < MAX_WORDS) {
            strcpy(wordCountArray[numWords].word, word);
            wordCountArray[numWords].count = 1;
            numWords++;
        }
    }
    else {
        wordCountArray[idx].count++;
    }
}
void processSentence(char* sentence) {
    char buffer[MAX_WORD_LENGTH];
    char* token = strtok(sentence, " ");

    while (token != NULL) {
        addOrIncrementWord(token);
        token = strtok(NULL, " ");
    }
}
void printUniqueWords() {
    printf("Unique words:\n");
    for (int i = 0; i < numWords; ++i) {
        if (wordCountArray[i].count == 1) {
            printf("%s\n", wordCountArray[i].word);
        }
    }
}
int main() 
{
    char sentence[] = "the quick brown fox jumps over the lazy dog";
    processSentence(sentence);
    printUniqueWords();
    return 0;
}