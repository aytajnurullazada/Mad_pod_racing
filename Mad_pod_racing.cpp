#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{

    bool useBoost = true;
    int min = 100000;

    // game loop
    while (1) {
        int x;
        int y;
        int next_checkpoint_x; // x position of the next check point
        int next_checkpoint_y; // y position of the next check point
        int next_checkpoint_dist; // distance to the next checkpoint
        int next_checkpoint_angle; // angle between your pod orientation and the direction of the next checkpoint
        cin >> x >> y >> next_checkpoint_x >> next_checkpoint_y >> next_checkpoint_dist >> next_checkpoint_angle; cin.ignore();
        int opponent_x;
        int opponent_y;
        cin >> opponent_x >> opponent_y; cin.ignore();

        int thrust = 100;
        
        int distance_to_opponent = sqrt(pow(x - opponent_x, 2) + pow(y - opponent_y, 2));

        if (abs(next_checkpoint_angle) > 90) {
            thrust = 0;
        } else if (abs(next_checkpoint_angle) > 60) {
            thrust = 50;
        } else if (abs(next_checkpoint_angle) > 30) {
            thrust = 80;
        }

        if (distance_to_opponent <= 870) {
            thrust = 5;
        }
        // if (distance_to_opponent < min) {
        //     min = distance_to_opponent;
        // }

        cerr << "THRUST : " << thrust << endl;
        cerr << "Use Boost " << useBoost << endl;


        if (next_checkpoint_angle == 0 && next_checkpoint_dist > 6000 && useBoost == true) {
            cout << next_checkpoint_x << " " << next_checkpoint_y << " BOOST" << endl;
            useBoost = false;
            cerr << " BOOST" << endl;
        } else {
            cout << next_checkpoint_x << " " << next_checkpoint_y << " " << thrust << endl;
        }


        cerr << "Next checkpoint distance : " << next_checkpoint_dist << endl;
        cerr << "Next checkpoint angle : " << next_checkpoint_angle << endl;
        cerr << "Min Distance to opponent " << min << endl;

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"
        
    }
}
