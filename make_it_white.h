using namespace std;

class MakeItWhite : public Plugin {
    public:


    void apply_filter(int img[5][5]) {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                img[i][j] = 255;
            }
        }
    }
};