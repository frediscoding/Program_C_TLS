#include <iostream>
using namespace std;

int main(){
	char option;
	float matriksA[10][10], matriksB[10][10], matriksC[10][10];
	int k; 

	cout << "This is a simple calculator for (square) matrices. \nUsed with great knowledge of linear algebra and you'd probably invent new math lol" << endl;

	cout << "Insert matrix size (k x k): "; 
    cin >> k;

	// untuk mengisi elemen di matriks A, dimulai dari elemen a11 menggunakan perulangan
    cout << "Insert matrix A (default) elements: " << endl;			
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= k; j++){
            cout << "Enter a value for a" << i << j << endl;
			cin >> matriksA[i][j];
		}
	}
	// display matriks A untuk meyakinkan user
    cout << "Your matrix A is: " << endl;
    for(int i = 1; i <= k; i++){
		for(int j = 1; j <= k; j++){
			cout <<  matriksA[i][j] << " ";
		}
        cout << endl;
	}

	// untuk mengisi elemen di matriks B, dimulai dari elemen b11 menggunakan perulangan. matriks B opsional (bisa diisi 0 semua saja)
	cout << "Insert matrix B (additional) elements: " << endl;		
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= k; j++){
                cout << "Enter a value for b" << i << j << endl;
				cin >> matriksB[i][j];
		}
	}

	// display matriks B
    cout << "Your matrix B is: " << endl;
    for(int i = 1; i <= k; i++){
		for(int j = 1; j <= k; j++){
			cout << matriksB[i][j] << " ";
		}
        cout << endl;
	}

	// display pilihan untuk operasi matriks yang tersedia
	cout << "(+) is to add, (-) is to subtract, (*) is for matrix multiplication, (@) is for matrix elimination, and (#) for scalar multiplication" << endl;
	cin >> option; 
	
	// menggunakan switch untuk mempermudah harus melakukan operasi yg mana based on input dari user
	switch(option){
	case '+': // pertambahan matriks
			for(int i = 1; i <= k; i++){
				for(int j = 1; j <= k; j++){
					cout << matriksA[i][j] + matriksB[i][j] << " ";
				}
				cout << endl;
			}
	break;
	case '-': // pengurangan matriks
			for(int i = 1; i <= k; i++){
				for(int j = 1; j <= k; j++){
					cout << matriksA[i][j] - matriksB[i][j] << " ";
				}
			cout << endl;
			}
	break;
	case '*': // perkalian matriks menggunakan dot product

	// deklarasi matriks C sementara untuk menampung hasil kali matriks A dan B
    for(int i = 1; i <= k; i++){
		for(int j = 1; j <= k; j++){
			matriksC[i][j] = 0;
		}
	}
			for(int i = 1; i <= k; i++){
                 for(int j = 1; j <= k; j++){
					for(int n = 1; n <= k; n++){
						matriksC[i][j] += matriksA[i][n] * matriksB[n][j];
						}
					}
				 }

			// display matriks C untuk menampilkan hasil perkalian
			for(int i = 1; i <= k; i++){
				for(int j = 1; j <= k; j++){
					cout << matriksC[i][j] << " ";
				}
				cout << endl;
			}
	break;  
	case '#': // perkalian skalar matriks
		int s;
		cout << "Insert scalar value: " << endl;
		cin >> s;
			cout << "Your new matrix A is: " << endl;
			for(int i = 1; i <= k; i++){
				for(int j = 1; j <= k; j++){
					cout << s * matriksA[i][j] << " ";
				}
				cout << endl;
			}
	break;
	case '@': // digunakan untuk menyelesaikan persamaan linear dengan melakukan eliminasi Gauss hingga menghasilkan upper triangular matrix
	cout << "This is a Gauss Elimination algorithm to return an upper triangular matrix of matrix A " << endl;
	int l;

		for(int i = 1; i <= k; i++){
            if(matriksA[i][i] == 0.0){
                cout << "Error, please do permutation first." << endl;
            }
			for(int j = 1; j <= k; j++){
				if(i != j && i < j){ // i < j memastikan bahwa yg dieliminasi adalah elemen di bawah diagonal, hence the mame upper triangular
					l = matriksA[j][i]/matriksA[i][i];
                    for(int n = 1; n <= k; n++){
                        matriksA[j][n] = matriksA[j][n] - l*matriksA[i][n];
                    }
				} 
				}
			}

		// display matriks yang sudah dieliminasi
		cout << "Your  Matrix is " << endl;
		for(int j = 1; j <= k; j++){
			for(int n = 1; n <= k; n++){
				cout << matriksA[j][n] << " ";
			}
		cout << endl;
		}
	break;
	default: // default case jika user tidak meng-input opsi yang sesuai dengan yang tersedia
		cout << "null" << endl;
	}

	return 0;
}