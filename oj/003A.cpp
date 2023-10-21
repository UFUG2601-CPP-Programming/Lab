#include <iostream>

int main(){

    int n, m, k;

    std::cin >> n >> m >> k;

    char paint[n+1][m+1];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            paint[i][j] = '.';
        }
    }

    // Outer Loop for k instructions
    for(int i = 0; i < k; i++){
        
        int x, y;

        char p, d;

        std::cin >> x >> y >> p >> d;

        switch(d){
            case 'U':
                for(int i = x; i > 0; i--){
                    paint[i][y] = p;
                }
                break;
            case 'D':
                for(int i = x; i <= n; i++){
                    paint[i][y] = p;
                }
                break;
            case 'L':
                for(int i = y; i > 0; i--){
                    paint[x][i] = p;
                }
                break;
            case 'R':
                for(int i = y; i <= m; i++){
                    paint[x][i] = p;
                }
                break;
            default: return -1; break;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            std::cout << paint[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}
