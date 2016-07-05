#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <math.h>

using namespace std;

#define N                128
#define TIME_JUMP_TRACK  400
#define TIME_JUMP_SECTOR 1
#define TIME_READ_DATA   10
#define MAX_SECTORS      360

bool readData(char* filename, int& n, vector<pair<int, int> >& data)  {
    ifstream infile(filename);
    infile >> n;

    for(int i = 0; i < n; i++) {
        int track;
        int sector;
        infile >> track >> sector;
        data.push_back(pair<int, int>(track, sector));
    }

    return true;
}

int time_jump_track(const pair<int, int>& x, const pair<int, int>& y) {
    int track_offset = (x.first > y.first) ? (x.first - y.first) : (y.first - x.first);
    return track_offset * TIME_JUMP_TRACK;
}

int time_jump_sector(const pair<int, int>& x, const pair<int, int>& y) {
    int sector_offset = (x.second > y.second) ? (x.second - y.second) : (y.second - x.second);
    sector_offset = (sector_offset < MAX_SECTORS/2) ? sector_offset : (MAX_SECTORS - sector_offset);
    return sector_offset * TIME_JUMP_SECTOR;
}

unsigned long calculate_time(const vector< pair<int, int> >& data, const bitset<N>& flags, bool need_back) {
    unsigned long sum_time(0);
    int count = data.size();
    pair<int, int> previous(0, 0);

    // go up
    for (int i = 0; i < count; i++) {
        // jump track
        sum_time += time_jump_track(previous, data[i]);
        previous.first = data[i].first;

        // jump sector (bit 0 means read when go up)
        if (!flags[i] || (i == count - 1)) {
            sum_time += time_jump_sector(previous, data[i]);
            previous.second = data[i].second;
        }
    }

    // go down
    if (need_back) {
        for (int i = count - 2; i >= 0; i--) {
            // jump track
            sum_time += time_jump_track(previous, data[i]);
            previous.first = data[i].first;

            // jump sector (bit 1 means read when do down)
            if (flags[i]) {
                sum_time += time_jump_sector(previous, data[i]);
                previous.second = data[i].second;
            }
        }

        // back to track 0
        sum_time += time_jump_track(previous, pair<int, int>(0, 0));
        previous.first = 0;

        // back to sector 0
        sum_time += time_jump_sector(previous, pair<int, int>(0, 0));
        previous.second = 0;
    }

    // plus read time
    sum_time += count * TIME_READ_DATA;

    return sum_time;
}

int main(int argc, char** argv)
{
    int n(0);
    vector<pair<int, int> > data;

    readData(argv[1], n, data);

    unsigned long time1 = calculate_time(data, bitset<N>(0), false);
    unsigned long time2 = calculate_time(data, bitset<N>(0), true);

    for (unsigned long long index = 1; index < pow(2, n); index++) {
        unsigned long temp = calculate_time(data, bitset<N>(index), true);
        if (temp < time2) {
            time2 = temp;
        }
    }

    cout << time1 << endl << time2 << endl;

    return 0;
}
