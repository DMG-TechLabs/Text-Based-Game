#include <unistd.h>  // for sleep()

#include <iostream>
#include <string>

#include "engine.h"

using namespace std;

void testSave() {
    Inventory *i = new Inventory();
    int day = 3;
    Node *n = new Node();
    AchievementCollection *ac = new AchievementCollection();

    new Save(i, day, ac, n);
}

int main(int argc, char *argv[]) {
    //saveObject<Item>("test.dat");

}
/*
int main(int argc, char *argv[]){
    cout << "starting Main" << endl;          
    boost::thread workerThread(ThreadworkerFunc);    
      
    cout << "main  waiting for thread" <<endl;          
    workerThread.join();    
      
    cout << "main Finished" << endl;          
    return 0;
}*/
