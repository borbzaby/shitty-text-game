#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <conio.h> // For _getch()
using namespace std;

// Variables needed in many functions
int px = 0, py = 0;
string player = "T";
char input;
int sw = 0, sh = 0;
int lives = 3, score = 0;

// gotta do this. otherwise the program has no idea the functions exist
void RenderScreen(vector<vector<string>> TheArr);
void GetInput(char& TheInput);


signed main()
{
    // we're not playing football here
    vector<vector<string>> playingfield;

    // Size setup (will be pre-entered when we have a fixed screen)
    cout << "\033[2J\033[1;1H";
    cout << "What should the width of the screen be?" << endl;
    cin >> sw;
    cout << "What should the height of the screen be?" << endl;
    cin >> sh;
    cout << "\033[2J\033[1;1H";

    // Resize playing field to width sw and height sh, with each element initialized to "░"
    playingfield.resize(sh-1, vector<string>(sw, "░"));

    while(true)
    {
        // Renders out the playing field and then clears the screen
        RenderScreen(playingfield);
        GetInput(input);
        this_thread::sleep_for(std::chrono::milliseconds(70));
        cout << "\033[2J\033[1;1H";
    }
    return 0;
}

//Literally just what the function name is. renders the stuff with 100% professional code
void RenderScreen(vector<vector<string>> TheArr)
{
    cout <<"[LIVES]: " << lives <<"         [SCORE]: " << score << endl;
    for(int i = 0; i < TheArr.size(); i++) {
        for(int k = 0; k < TheArr[i].size(); k++) {
            /* Checks if that pos in the array is where the player is
            if it is, it will output the player, otherwise it will output blank */
            if(i == py && k == px) {
                cout << player;
                if (k < TheArr[i].size() - 1) {
                    cout << "░";
                }
            }
            else {
                cout << TheArr[i][k];
                if (k < TheArr[i].size() - 1) {
                    cout << "░";
                }
            }
        }
        cout << endl;
    }
}

//accepts input 
void GetInput(char& TheInput)
{
    while (true) {
        if (_kbhit()) { //I have no idea what _kbhit means, but apparently it will fix the no enter problem
            TheInput = _getch(); /*Capture one character input. only on windows?
                                 getch sounds like a troll having terrible vomiting*/ 
            if (TheInput == 'w' && py > 0) {
                py--;
                break;
            }
            else if (TheInput == 's' && py < sh - 2) {
                py++;
                break;
            }

            else if (TheInput == 'd' && px < sw - 1) {
                px++;
                break;
            }
            else if (TheInput == 'a' && px > 0) {
                px--;
                break;
            }
        }
    }
}