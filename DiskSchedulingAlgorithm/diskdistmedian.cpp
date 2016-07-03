// Example explanation
// 5
// 1 30               
// 3 359              
// 5 0
// 10 20
// 12 30

// Median sector: 15
// left: (3,359) (5,0)
// right: (10,20) (12,30) (1,30)

//                                            *(0,0)
//					                      /            \          
//										/				  *(1,30)
//		                              *(3,359)                |
//									      \                   |
//									        \                 |
//										      *(5,0)          |
//										       \              |
//											     \            |
//												  \           |
//                                                 *(10,20)   |
//												          \   |
//														   \  |
//                                                        *(12,30)														
//
// This could be lowest cost path.	

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
    unsigned int nTrack;
    unsigned int nSec;
    unsigned int costToFetchData(DiskPos pos)
    {
        unsigned int trackCost = abs(pos.nTrack- nTrack) * COST_TRACK;
        unsigned int sectorCost = abs(pos.nSec - nSec) > 180 ? TOTAL_SECTOR - abs(pos.nSec - nSec) : abs(pos.nSec - nSec);
        return trackCost + sectorCost + COST_FETCH_DATA;
    }
};

class DataSet
{
public:
    DataSet() 
    {
        setSize = 0;    
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
            vecPosSet.push_back(DiskPos(track, sector));
        }
	}
	
	void computeMinCost()
	{
        unsigned int medianSector = findMedianSector();
        printf("Median sector %d\n", medianSector);
        fillLeftAndRightSectors(medianSector);
        
        unsigned int totalCost = 0;
        DiskPos startPos(0, 0);
        printf("Compute minimal cost - start %d %d\n", startPos.nTrack, startPos.nSec);

        // Compute cost and print out the disk fetch sequence for left
        for (vecPosSetType::iterator it = leftVecPosSet.begin(); it != leftVecPosSet.end(); it++)
        {
            if (it == leftVecPosSet.begin())
            {
                totalCost += startPos.costToFetchData(*it);
            }

            if ((it + 1) != leftVecPosSet.end())
            {
                totalCost += (*it).costToFetchData(*(it + 1));
            }
            else 
            {
                // Connect left and right
                vecPosSetType::reverse_iterator right_rbegin_it = rightVecPosSet.rbegin();
                if (right_rbegin_it != rightVecPosSet.rend())
                {
                    totalCost += (*it).costToFetchData(*right_rbegin_it);
                }
            }

            printf("%d %d\n", (*it).nTrack, (*it).nSec);
        }

        // Compute cost and print out the disk fetch sequence for right, reversed sequence on right vec
        for (vecPosSetType::reverse_iterator it = rightVecPosSet.rbegin(); it != rightVecPosSet.rend(); it++)
        {
            if ((it + 1) != rightVecPosSet.rend())
            {
                totalCost += (*it).costToFetchData(*(it + 1));
            }
            else
            {
                totalCost += (*it).costToFetchData(startPos);
            }
            printf("%d %d\n", (*it).nTrack, (*it).nSec);
        }
        printf("%d %d\n", startPos.nTrack, startPos.nSec);
        // Returning back to 0, 0 doesn't need fetch data.
        printf("total cost %d\n", totalCost -= COST_FETCH_DATA);
    }
	
private:
    unsigned int findMedianSector()
    {
        unsigned int sum;
        unsigned int median;
        for (vecPosSetType::iterator it = vecPosSet.begin(); it != vecPosSet.end(); it++)
        {
            if ((*it).nSec >= 180)
            {
                sum += (*it).nSec;
            }
            else 
            {
                sum += (*it).nSec + TOTAL_SECTOR;
            }
        }
        median = sum / setSize;
        
        return median % 360;
    }
    
    void fillLeftAndRightSectors(unsigned int median)
    {
        
        for (vecPosSetType::iterator it = vecPosSet.begin(); it != vecPosSet.end(); it++)
        {
            if (median < 180)
            {
                if (((*it).nSec < 180 && (*it).nSec <= median) || 
                    ((*it).nSec >= 180))
                {
                    leftVecPosSet.push_back(*it);
                }
                else 
                {
                    rightVecPosSet.push_back(*it);
                }
            }
            else
            {
                if ((*it).nSec >= 180 && (*it).nSec < median)   
                {
                    leftVecPosSet.push_back(*it);
                }
                else 
                {
                    rightVecPosSet.push_back(*it);
                }
            }
        }
        
        unsigned int leftSize = leftVecPosSet.size();
        unsigned int rightSize = rightVecPosSet.size();
        unsigned int rightIndex = 0;
        while (rightVecPosSet[rightIndex].nTrack < leftVecPosSet[leftSize - 1].nTrack)
        {
            rightIndex++;
        }
        
        unsigned int i = rightIndex, j = rightSize - 1;
        DiskPos tmp; 
        while (i < j)
        {
            tmp = rightVecPosSet[i];
            rightVecPosSet[i] = rightVecPosSet[j];
            rightVecPosSet[j] = tmp;
            i++;
            j--;
        }
    }
    
    unsigned int setSize;
    typedef vector<DiskPos> vecPosSetType;
    vecPosSetType vecPosSet;
    vecPosSetType leftVecPosSet;
    vecPosSetType rightVecPosSet;
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
						                               


