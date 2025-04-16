using namespace std;

class Plugin {
    public:
    // virtual void apply_filter(int img[5][5]) {
    //     cout << "Function apply_filter for Plugin called ... Not doing anything ... " << endl; 
    // }

    virtual void apply_filter(int img[5][5]) = 0;
};