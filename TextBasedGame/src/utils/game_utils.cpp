#include "game_utils.h"
#include <vector>


void saveToFile(string file_name, string text_data){
    ofstream file;
    file.open (file_name);
    file << text_data;
    file.close();
}

string loadFromFile(string file_name){
    string text_data;
    ifstream file;
    file.open (file_name);
    file >> text_data;
    file.close();

    return text_data;
}

template <typename T> 
void saveObject(string filename, T object_to_save)
{
    ofstream outfile;
    outfile.open(filename, ios::binary | ios::out);
    outfile.write(&object_to_save, sizeof(object_to_save));
    return;
}

template <typename T> 
T loadObject(string filename, T object_to_load)
{
    ifstream infile;
    infile.open("silly.dat", ios::binary | ios::in)
    infile.read(&object_to_load, sizeof(object_to_load));
    return object_to_load;
}
//void saveClass()

// void saveToBinary(string file_name, string data){
//     ofstream file;
//     file.open(file_name, ios::out | ios::binary);
//     file.write((char *) &data, sizeof(string));
//     file.close();
//     if(!file.good()) {
//         cout << "Error occurred at writing time!" << endl;
//         return;
//     }

// }

// string loadFromBinary(string file_name){
//     //string filename(file_name);
//     fstream file;
//     file.open(file_name, ios::in | ios::binary);
//     file.seekg(0, file.end);
//     size_t fileSize = file.tellg();
//     file.seekg(0, file.beg);
//     // auto file_size = filesystem
//     //auto file_size = filesystem::file_size(filename);
//     char *data= reinterpret_cast<char *>(new int[fileSize]);
//     file.read(data, fileSize);
//     std::string output(data);
//     cout << output << endl;
//     // string text_data;
//     // char buffer[1000];
//     // ifstream file;
//     // file.open(file_name, ios::in | ios::binary);
//     // file.read(buffer,1000);
//     // //file >> text_data;
//     // file.close();
//     // // if(!file.good()) {
//     // //     cout << "Error occurred at reading time!" << endl;
//     // //     //return "";
//     // // }
//     // text_data = buffer;
//     return "text_data";
// }

// void FileToString(const string& path) {
//     ifstream rf("text.txt", ios::out | ios::binary);
//     if(!rf) {
//         cout << "Cannot open file!" << endl;
//         return ;
//     }
//     char* data;
//     //Student rstu[3];
    
//     rf.read((char *) &data, 32);
//     rf.close();
//     if(!rf.good()) {
//         cout << "Error occurred at reading time!" << endl;
//         return ;
//     }
//     cout<< data <<endl;
    
    
// }

// /*
// void ThreadworkerFunc()  
// {  
//     boost::posix_time::seconds workTime(5);          
//     cout << "ThreadWorker: running" << endl;    
      
//     // Pretend to do something useful... 
//     boost::this_thread::sleep(workTime);          
//     cout << "ThreadWorker: finished" << endl;  
// }    */