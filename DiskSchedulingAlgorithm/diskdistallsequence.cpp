#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

const unsigned int COST_TRACK = 400;
const unsigned int HALF_TRACK_DISK = 180;
const unsigned int COST_SECTOR = 1;
const unsigned int COST_FETCH_DATA = 10;
const unsigned int TOTAL_SECTOR = 360;

class DiskPos
{
public: 
    DiskPos(unsigned int track, unsigned int sec)
    {
        nTrack = track;
        nSec = sec;
    }
    
    DiskPos() {};
    
    operator =(DiskPos src)
    {
        nTrack = src.nTrack;
        nSec = src.nSec;
    }
    
    unsigned int costToFetchData(DiskPos pos) const
    {
        unsigned int trackCost = abs(pos.nTrack- nTrack) * COST_TRACK;
        unsigned int sectorCost = abs(pos.nSec - nSec) > 180 ? TOTAL_SECTOR - abs(pos.nSec - nSec) : abs(pos.nSec - nSec);
        return trackCost + sectorCost + COST_FETCH_DATA;
    }
    
    void print()
    {
        printf("%d, %d\n", nTrack, nSec);
    }

private:
    unsigned int nTrack;
    unsigned int nSec;
};

class DataSet
{
public:
    DataSet() : startPos(0, 0)
    {
        setSize = 0;    
        minCost = 0xFFFFFFF;
    }
    
    void readDataFromFile(const char* strFileName)
	{
        ifstream fileIn(strFileName);
        unsigned int track;
        unsigned int sector;
        
        fileIn >> setSize;
        printf("Read file - size %d\n", setSize);
        for (unsigned int index = 0; index < setSize; index++)
        {
            fileIn >> track >> sector;
            printf("Read file - track %d, sector %d\n", track, sector);
            vecPosSetRaw.push_back(DiskPos(track, sector));
        }
        
        vecPosSetTmp = vecPosSetRaw;
	}
    
    void computeMinCost()
    {
        walkThroughAllSequenceForMinCost(0, setSize - 1);
        printMin();
    }    
    
private:
    void walkThroughAllSequenceForMinCost(unsigned int start, unsigned int end)
    {
        if (start > end)
        {
            unsigned int curCost = computeCost();
            printf("curCost %d\n\n\n\n", curCost);
            if (minCost > curCost)
            {
                minCost = curCost;
                vecPosSetMin = vecPosSetTmp;
            }
        }
        else
        {
            for (unsigned int index = start; index <= end; index++)
            {
                swapVecElem(start, index);
                walkThroughAllSequenceForMinCost(start + 1, end);
                swapVecElem(start, index);
            }
        }
    }
    
    unsigned int computeCost()
    {
        unsigned int totalCost = 0;
        vecPosSetType::iterator it = vecPosSetTmp.begin();
        if (it != vecPosSetTmp.end())
        {
            totalCost += startPos.costToFetchData(*it);
        }
        
        for (; it != vecPosSetTmp.end(); it++)
        {
            if (it + 1 != vecPosSetTmp.end())
            {
                totalCost += (*it).costToFetchData(*(it + 1));
            }
            else
            {
                break;
            }
        }
        
        totalCost += (*it).costToFetchData(startPos) - COST_FETCH_DATA;
        printTmp();
        return totalCost;
    }
    
    void swapVecElem(unsigned int posOne, unsigned int posTwo)
    {
        DiskPos tmp;
        tmp = vecPosSetTmp[posOne];
        vecPosSetTmp[posOne] = vecPosSetTmp[posTwo];
        vecPosSetTmp[posTwo] = tmp;
    }
    
    void printMin()
    {
        for (vecPosSetType::iterator it = vecPosSetMin.begin(); it != vecPosSetMin.end(); it++)
        {
            (*it).print();
        }
        
        printf("Min cost %d\n", minCost);
    }
    
    void printTmp()
    {
        for (vecPosSetType::iterator it = vecPosSetTmp.begin(); it != vecPosSetTmp.end(); it++)
        {
            (*it).print();
        }
    }
    
    unsigned int setSize;
    typedef vector<DiskPos> vecPosSetType;
    vecPosSetType vecPosSetRaw;
    vecPosSetType vecPosSetTmp;
    vecPosSetType vecPosSetMin;
    const DiskPos startPos;
    unsigned int minCost;
};

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("Wrong usage!\n");
        exit(1);
    }
    
    DataSet dataSet;
    dataSet.readDataFromFile(argv[1]);
    dataSet.computeMinCost();
    
    exit(0);
}