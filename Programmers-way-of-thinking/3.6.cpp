#include <vector>
#include <iostream>

using namespace std;

void VectorSurvey()
{
    vector<int> surveyData;
    surveyData.reserve(30);
    int surveyResponse;

    cout << "Enter next survey respone or -1 to end: ";
    cin >> surveyResponse;

    while(surveyResponse != -1){
        surveyData.push_back(surveyResponse);
        cout << "Enter next survey respone or -1 to end; ";
        cin >> surveyResponse;
    }

    int vectorSize = surveyData.size();
    const int MAX_RESPONSE = 10;
    int histgram[MAX_RESPONSE];

    // init
    for(int i=0;i<MAX_RESPONSE;i++){
        histgram[i] = 0;
    }

    // count
    for(int i=0;i<vectorSize;i++){
        histgram[surveyData[i] - 1]++;
    }

    // max
    int mostFrequent = 0;
    for(int i=1;i<MAX_RESPONSE;i++){
        if(histgram[i] > histgram[mostFrequent]) mostFrequent = i;
    }

    int mostFrequentNumber = mostFrequent+1;
    int mostFrequentNumberCount = histgram[mostFrequent];

    cout << "most frequent is " << mostFrequentNumber << " count " << mostFrequentNumberCount;
}

void VectorSurvey2()
{
    const int MAX_RESPONSE = 10;
    int histgram[MAX_RESPONSE];
    for (int i=0;i<MAX_RESPONSE; i++){
        histgram[i] = 0;
    }

    int surveyResponse;
    cout << "Enter next survey respone or -1 to end; ";
    cin >> surveyResponse;
    while(surveyResponse != -1){
        histgram[surveyResponse -1]++;
        cout << "Enter next survey respone or -1 to end; ";
        cin >> surveyResponse;
    }

    int mostFrequent = 0;
    for(int i=1;i<MAX_RESPONSE;i++){
        if(histgram[i] > histgram[mostFrequent]) mostFrequent = i;
    }

    int mostFrequentNumber = mostFrequent+1;
    int mostFrequentNumberCount = histgram[mostFrequent];

    cout << "most frequent is " << mostFrequentNumber << " count " << mostFrequentNumberCount;
}

int main()
{
    /* VectorSurvey(); */
    VectorSurvey2();
    return 0;
}
