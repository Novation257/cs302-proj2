// main.cpp
#include "volsort.h"
#include <iostream>
#include <cstdlib>
#include <strings.h>
#include <unistd.h>
using namespace std;

#define MODE_STL       0
#define MODE_QSORT     1
#define MODE_MERGE     2
#define MODE_QUICK     3
#define MODE_OBLIVIOUS 4

void usage(int status) {
    cout << "usage: volsort" << endl
              << "  -m MODE   Sorting mode (oblivious, stl, qsort, merge, quick)" << endl
              << "  -n        Perform numerical ordering" << endl;
    exit(status);
}

void parse_command_line_options(int argc, char *argv[], int &mode, bool &numeric) {
    int c;
    while ((c = getopt(argc, argv, "hm:n")) != -1) {
        switch (c) {
            case 'm':
	@@ -39,8 +32,8 @@ void parse_command_line_options(int argc, char *argv[], int &mode, bool &numeric
                    mode = MODE_MERGE;
                } else if (strcasecmp(optarg, "quick") == 0) {
                    mode = MODE_QUICK;
                } else if (strcasecmp(optarg, "oblivious") == 0) {
                    mode = MODE_OBLIVIOUS;
                } else {
                    usage(1);
                }
	@@ -58,22 +51,18 @@ void parse_command_line_options(int argc, char *argv[], int &mode, bool &numeric
    }
}

int main(int argc, char *argv[]) {
    int mode = MODE_STL;
    bool numeric = false;
    List data;
    string line;

    parse_command_line_options(argc, argv, mode, numeric);

    while (getline(cin, line)) {
        data.push_front(line);
    }

    switch (mode) {
        case MODE_STL:
            stl_sort(data, numeric);
	@@ -87,21 +76,17 @@ int main(int argc, char *argv[]) {
        case MODE_QUICK:
            quick_sort(data, numeric);
            break;
        case MODE_OBLIVIOUS:
            break;
    }

    for (Node *curr = data.head; curr != nullptr; curr = curr->next) {
        if (numeric) {
            cout << curr->number << endl;
        } else {
            cout << curr->string << endl;
        }
    }

    return 0;
}
