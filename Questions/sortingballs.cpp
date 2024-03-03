#include <iostream>
#include <vector>

using namespace std;

enum Color { RED, WHITE, BLUE };

void sortBalls(vector<Color>& balls) {
    int red = 0, white = 0, blue = balls.size() - 1;
    while (white <= blue) {
        if (balls[white] == RED) {
            swap(balls[red], balls[white]);
            red++;
            white++;
        } else if (balls[white] == BLUE) {
            swap(balls[white], balls[blue]);
            blue--;
        } else {
            white++;
        }
    }
}

int main() {
    vector<Color> balls = {RED, WHITE, BLUE, WHITE, RED, BLUE, RED, WHITE, BLUE};
    sortBalls(balls);
    cout << "Sorted balls: ";
    for (Color ball : balls) {
        cout << ball << " ";
    }
    cout << endl;
    return 0;
}
//complexity O(n)