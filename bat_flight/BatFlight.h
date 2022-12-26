// Radoslaw Dabkowski (325683)

#include <string>

class BatFlight {
public:
    BatFlight(int x0, int y0, int w, int h) : x0(x0), y0(y0), w(w), h(h) {
        x1 = 0;
        x2 = w - 1;
        y1 = 0;
        y2 = h - 1;
    }
    void DoJump(const std::string& bombDir) {
        // Update the square of possible bomb locations

        // speedy no branching solution ;)
        switch (bombDir[0]) {
            case 'U':
                y2 = y0 - 1;
                break;
            case 'R':
                x1 = x0 + 1;
                break;
            case 'D':
                y1 = y0 + 1;
                break;
            case 'L':
                x2 = x0 - 1;
                break;
        }

        switch (bombDir[bombDir.size() - 1]) {
            case 'R':
                x1 = x0 + 1;
                break;
            case 'L':
                x2 = x0 - 1;
                break;
        }

        // Calculate where Batman should jump to
        x0 = (x1 + x2) / 2;
        y0 = (y1 + y2) / 2;
    }
    int curX() const { return x0; }
    int curY() const { return y0; }
private:
    int x0, y0; // Batman's current location
    int x1, x2; // The square of possible bomb locations
    int y1, y2;
    int w, h; // The width and height of the building
};
