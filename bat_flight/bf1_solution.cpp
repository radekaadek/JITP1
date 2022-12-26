#include <iostream>
#include <string>
#include <BatFlight.h>

using namespace std;


int main()
{
    int w; // width of the building.
    int h; // height of the building.
    cin >> w >> h; cin.ignore();
    int n; // maximum number of turns before game over.
    cin >> n; cin.ignore();
    int x0;
    int y0;
    cin >> x0 >> y0; cin.ignore();

    // Make a square of possible bomb locations
    int x1 = 0, x2 = w - 1;
    int y1 = 0, y2 = h - 1;

    // game loop
    // game loop
    BatFlight bf(x0, y0, w, h);
    while (1) {
        string bombDir; // the direction of the bombs from batman's
                        // current location (U, UR, R, DR, D, DL, L or UL)

        cin >> bombDir; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        bf.DoJump(bombDir);

        // the location of the next window Batman should jump to.
        cout << bf.curX() << " " << bf.curY() << endl;
    }
}