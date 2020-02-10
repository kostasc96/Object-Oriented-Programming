#include <iostream>
#include <string>

using namespace std;

static int id_for_post=1;
static string text_for_post[20]={"Keimeno1","Keimeno2","Keimeno3","Keimeno4","Keimeno5","Keimeno6","Keimeno7","Keimeno8","Keimeno9","Keimeno10","Keimeno11","Keimeno12","Keimeno13","Keimeno14","Keimeno15","Keimeno16","Keimeno17","Keimeno18","Keimeno19","Keimeno20"};
static string creator_for_post[20]={"Kostas","Adam","Maria","Angela","John","Giannis","Konstantinos","Nick","Katerina","Georgia","Alex","Kevin","Andreas","Ashley","Taylor","Ben","Jack","Billy","David","Christina"};
static string title_for_post[20]={"Title1","Title2","Title3","Title4","Title5","Title6","Title7","Title8","Title9","Title10","Title11","Title12","Title13","Title14","Title15","Title16","Title17","Title18","Title19","Title20"};

static string subject_for_thread[5]={"Subject title 1","Subject title 2","Kanones kai xrhsimes plhrofories","Subject title 4","Subject title 5"};
static string creator_for_thread[5]={"Bill","Mary","Nikos","George","Anna"};

int get_id_for_post();
string get_text_for_post();
string get_creator_for_post();
string get_title_for_post();

string get_subject_for_thread(int );
string get_creator_for_thread(int );

