#include <iostream>
#include <string>
using namespace std;
class Music{
public:
    string name;
    Music *prev_music;
    Music *next_music;

    Music(string name){
        this->name = name;
        prev_music = nullptr;
        next_music = nullptr;
    }
};

class PlayList {
public:
    Music *head;
    Music *tail;
    PlayList(){
        head = nullptr;
        tail = nullptr;
    }

    void addMusic (string name){
        Music *new_music = new Music(name);
        if (!head){
            head = new_music;
            tail = new_music;
        }else{
            tail->next_music = new_music; // tail->next_music ตัว tail คือ เพลงเก่าที่ใส่ก่อนหน้า
            new_music->prev_music = tail;//  new_music->prev_music เป็นการชี้ตำแหน่งของเพลงเก่า
            tail = new_music; // ใส่ตำแหน่ง tail ใหม่
        }
    }

    bool removeMusic (string name){
        Music *temp = head; // ให้ temp เริ่มที่ หัว
        while (temp != nullptr){ // ลูปไป temp ทีละตัว
            if(temp->name == name){ // เช็คว่า temp name ตัวนั้น ชื่อเดียวกับ name ที่ส่งมาไหม
                if(temp->prev_music){ //เช็คว่า temp ตัวที่เลือกมามี เพลงด้านหลังไหม
                    temp->prev_music->next_music = temp->next_music; // ถ้ามีเพลงด้านหลังให้เข้าไปที่ next_music ของเพลงด้านหลังแล้ว ใส่ เพลงต่อไปที่ temp ที่เลือกมาชี้ไป
                }
                if(temp->next_music){ // เช็คว่า temp ตัวที่เลือกมามี เพลงด้านหน้าไหม
                    temp->next_music->prev_music = temp->prev_music; // ถ้ามีเพลงด้านหน้าให้เข้าไปที่ prev_music ของเพลงด้านหน้าแล้ว ใส่ เพลงด้านหลังของ temp ที่เลือกมา
                }
                if(temp == head){ // เช็คว่า temp นั้นเป็น head ไหม
                    head = temp->next_music; // ถ้า temp นั้นเป็น head ให้เปลี่ยน head ใหม่เป็นตัวด้านหน้าที่ temp ที่เลือกมาชี้ไป
                }
                if(temp == tail){ // เช็คว่า temp นั้นเป็น tail ไหม
                    tail = temp->prev_music; // ถ้า temp นั้นเป็น tail ให้เปลี่ยน tail ใหม่เป็นตัวด้านหลังที่ temp ที่เลือกมาชี้ไป
                }
                delete temp; // ลบ temp ทิ้ง
                return true;
            }
        temp = temp->next_music; // ตัวใช้วนลูปหาเฉยๆ
        }
        return false;
    }
    void display() {
        Music *temp = head;
        while (temp != nullptr) {
            cout << temp->name << endl;
            temp = temp->next_music;
        }
    }
};

int main(){
PlayList myPlaylist;
  myPlaylist.addMusic("Song 1");
  myPlaylist.addMusic("Song 2");
  myPlaylist.addMusic("Song 3");

  cout << "Current Playlist:" << endl;
  myPlaylist.display();

  myPlaylist.removeMusic("Song 2");
  cout << "\nPlaylist after removing a song:" << endl;
  myPlaylist.display();
    return 0;
}