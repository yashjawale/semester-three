#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

class Polygon {
    private:
        int p[10][10], trans_result[10][10], trans_matrix[10][10];
        float rotation_result[10][10], rotation_matrix[10][10];
        float scaling_result[10][10], scaling_matrix[10][10];
        float shearing_result[10][10], shearing_matrix[10][10];
        int reflection_result[10][10], reflection_matrix[10][10];

    public:
        int accept_polygon(int [][10]);
        void draw_polygon(int [][10], int);
        void draw_polyfloat(float [][10], int);
        void matmult(int [][10], int [][10], int, int, int, int [][10]);
        void matmultfloat(float [][10], int [][10], int, int, int, float [][10]);
        void shearing(int [][10], int);
        void scaling(int [][10], int);
        void rotation(int [][10], int);
        void translation(int [][10], int);
        void reflection(int [][10], int);
};

int Polygon::accept_polygon(int p[][10]) {
    int i, n;
    cout << "\n\n\t\tEnter no. of vertices: ";
    cin >> n;
    for(i=0; i<n; i++) {
        cout << "\n\n\t\tEnter (x,y) coordinates of point P" << i << ": ";
        cin >> p[i][0] >> p[i][1];
        p[1][2] = 1;
    }
    for (i=0; i<n; i++) {
        cout << "\n";
        for (int j=0; j<3; j++) {
            cout << p[i][j] << "\t";
        }
    }
    return n;
}

void Polygon::draw_polygon(int p[][10], int n) {
    int i, gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    line(320, 0, 320, 480);
    line(0, 240, 640, 240);
    for (i=0; i<n; i++) {
        if (i<n-1) {
            line(p[i][0]+320, -p[i][1]+240, p[i+1][0]+320,-p[i+1][1]+240);
        } else {
            line(p[i][0]+320, -p[i][1]+240, p[0][0]+320, -p[0][1]+240);
        }
        delay(3000);
    }
}


void Polygon::draw_polyfloat(float p[][10], int n) {
    int i, gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    line(320, 0, 320, 480);
    line(0, 240, 640, 240);
    for (i=0; i<n; i++) {
        if (i<n-1) {
            line(p[i][0]+320, -p[i][1]+240, p[i+1][0]+320, -p[i+1][1]+240);
        }
        else {
            line(p[i][0]+320, -p[i][1]+240, p[0][0]+320, -p[0][1]+240);
        }
    }
}

void Polygon::translation(int p[10][10], int n) {
    int tx, ty, i, j; 
    int i1, j1, k1, r1, c1, c2;
    r1=n;
    c1=c2=3;
    cout << "\n\n\t\tEnter X translation tx: ";
    cin >> tx;
    cout << "\n\n\t\tEnter Y translation ty: ";
    cin >> ty;
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            trans_matrix[i][j] = 0;
        }
    }
    trans_matrix[0][0] = trans_matrix[1][1] = trans_matrix[2][2] = 1;
    trans_matrix[2][0] = tx;
    trans_matrix[2][1] = ty;
    for(i1=0; i1<10; i1++) {
        for(j1=0; j1<10; j1++) {
            trans_result[i1][j1] = 0;
        }
    }
    for (i1=0; i1<r1; i1++) {
        for (j1=0; j1<c2; j1++) {
            for (k1=0; k1<c1; k1++) {
                trans_result[i1][j1] = trans_result[i1][j1] + (p[i1][k1] * trans_matrix[k1][j1]);
            }
        }
    }
    cout << "\n\n\t\tPolygon after translation: ";
    draw_polygon(trans_result, n);
}

void Polygon::rotation(int p[][10], int n) {
    float type, Ang, Sinang, Cosang;
    int i, j;
    int i1, j1, k1, r1, c1, c2;
    r1 = n;
    c1 = c2 = 3;
    cout << "\n\n\t\tEnter the angle of rotation in degrees: ";
    cin >> Ang;
    cout << "\n\n ----- Rotation Types -----";
    cout << "\n\n\t\t!. Clockwise rotation \n\n\t\t2.Anti-Clockwise rotation";
    cout << "\n\n\t\tEnter your choice(1-2): ";
    cin >> type;
    Ang = (Ang*6.2832)/360;
    Sinang = sin(Ang);
    Cosang = cos(Ang);
    cout << "Mark1";
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            rotation_matrix[1][j] = 0;
        }
    }
    cout << "Mark2";
    rotation_matrix[0][0] = rotation_matrix[1][1] = Cosang;
    rotation_matrix[0][1] = rotation_matrix[1][0] = Sinang;
    rotation_matrix[2][2] = 1;
    if (type == 1) {
        rotation_matrix[0][1] = -Sinang;
    } else {
        rotation_matrix[1][0] = -Sinang;
    }
    for (i1=0; i1<10; i1++) {
        for (j1=0; j1<10; j1++) {
            rotation_result[i1][j1] = 0;
        }

        for (i1=0; i1<r1; i1++) {
            for (j1=0; j1<c2; j1++) {
                for (k1=0; k1<c1; k1++) {
                    rotation_result[i1][j1] = rotation_result[i1][j1] + (p[i1][k1] * rotation_matrix[k1][j1]);
                }
            }
        }
        cout << '\n\n\t\tPolygon after rotation: ';
        for (i=0; i<n; i++) {
            cout << "\n";
            for (int j =0; j<3; j++) {
                cout << rotation_result[1][j] << "\t";
            }
        }
        draw_polyfloat(rotation_result, n);
    }
}

void Polygon::scaling(int p[][10], int n) {
    float sx, sy;
    int i, j;
    int i1, j1, k1, r1, c1, c2;
    r1=n; 
    c1=c2=3;
    cout << "\n\n\t\tEnter X scaling Sx: ";
    cin >> sx;
    cout << "\n\n\t\tEnter Y scaling Sy: ";
    cin >> sy;

    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            scaling_matrix[i][j] = 0;
        }
    }

    scaling_matrix[0][0] = sx;
    scaling_matrix[0][1] = 0;
    scaling_matrix[0][2] = 0;
    scaling_matrix[1][0] = 0;
    scaling_matrix[1][1] = sy;
    scaling_matrix[1][2] = 0;
    scaling_matrix[2][0] = 0;
    scaling_matrix[2][1] = 0;
    scaling_matrix[2][2] = 1;

    for (i1=0; i1<10; i1++) {
        for (j1=0; j1<10; j1++) {
            scaling_result[i1][j1] = 0;
        }
    }

    for(i1=0; i1<r1; i1++) {
        for(j1=0; j1<c2; j1++) {
            for(k1=0; k1<c1; k1++) {
                scaling_result[i1][j1] = scaling_result[i1][j1] + (p[i1][k1] * scaling_matrix[k1][j1]);
            }
        }
    }

    cout << "\n\n\t\tPolygon after scaling: ";
    draw_polyfloat(scaling_result, n);
}

int main() {
    int ch, n, p[10][10];
    Polygon p1;
    cout << "\n\n ----- 2D Transformation -----";
    n = p1.accept_polygon(p);
    cout << "\n\n\t\tOriginal Polygon: ";
    p1.draw_polygon(p, n);
    do {
        int ch;
        cout << "\n\n----- 2D transformation -----";
        cout << "\n\n\t\t1. Translation \n\n\t\t2. Scaling \n\n\t\t3. Rotation \n\n\tt4. Exit";
        cout << "\n\n\tEnter your choice(1-6): ";
        cin >> ch;
        switch(ch) {
            case 1:
                p1.translation(p, n);
                break;
            case 2:
                p1.scaling(p, n);
                break;
            case 3:
                p1.rotation(p, n);
                break;
            case 4:
                exit(0);
        }
    } while(1);
    return 0;
}