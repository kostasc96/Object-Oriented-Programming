#include <iostream>
#include <string>
#include "date.h"
#include "data.h" 

using namespace std;



class Post
{
    private:
    int id;
    string title;
    string creator;
    string text;
    Date d;
    public:
    void set_id(int );
    void set_title(string );
    void set_creator(string );
    void set_text(string );
    int get_id();
    string get_title();
    string get_creator();
    string get_text();
    void print_post();
     Post(int ,string ,string ,string ,Date );
    ~Post();
};


