#include<bits/stdc++.h> 

using namespace std;

int dp[1000][1000];

int knapsack(int maxTime, const vector<int>& time, const vector<int>& score, vector<bool>& selectedItems, bool study) {
    int n = time.size();
    if (study) {
        memset(dp, 1000000, sizeof(dp));
        dp[0][0] = 0;
    } else {
        memset(dp, 0, sizeof(dp));
    }

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= maxTime; ++w) {
            if (time[i - 1] <= w) {
                if (study) {
                    dp[i][w] = min(score[i - 1] + dp[i - 1][w - time[i - 1]], dp[i - 1][w]);
                } else
                {
                    dp[i][w] = max(score[i - 1] + dp[i - 1][w - time[i - 1]], dp[i - 1][w]);
                }   
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    
    }    

    // Reconstruimos la selección de elementos
    int totalValue = dp[n][maxTime];
    int remainingCapacity = maxTime;
    for (int i = n; i > 0 && totalValue > 0; --i) {
        if (totalValue != dp[i - 1][remainingCapacity]) {
            selectedItems[i - 1] = true;
            totalValue -= score[i - 1];
            remainingCapacity -= time[i - 1];
        }
    }

    return dp[n][maxTime];
}

static void menu();
static void choice1();
static void choice2();

static void menu() {
    int choice;
    cout << "--------------Bienvenidos a Max Grade--------------" << endl;
    cout << endl;
    cout << "1. Sacar nota máxima" << endl;
    cout << "2. Eficiencia en el estudio" << endl;
    cout << "3. Salir" << endl;
    cout << endl;
    cout << "Escoge una opción: " << endl;
    cin >> choice;
    if (choice == 1) {
        choice1();
    } else if (choice == 2) {
        choice2();
    } else if (choice != 3) { 
        cout << endl<< endl<< endl<< endl<< "Esa opción no existe, intentalo de nuevo" << endl;
        menu();
    } else {
        cout << " Vuelva pronto";
    }
      
}

static void choice1 () {
    bool study = false;
    vector<int> time;
    vector<int> score;
    int maxTime;
    int exercises;
    cout << "Introduce la cantidad de ejercicios: ";
    cin >> exercises;
    for(int i = 1; i <= exercises; i++){
        int exTime, exScore;
        cout << "Introduce el tiempo que cuesta hacer el ejercicio " << i << ":";
        cin >> exTime;
        cout << endl << "Introduce el puntaje del ejercicio " << i << ":"  << endl;
        cin >> exScore;
        time.push_back(exTime);
        score.push_back(exScore);
    }
    cout << endl << "Introduce el tiempo que dura el examen: ";
    cin >> maxTime;

    vector<bool> selectedItems(time.size(), false);
    int maxGrade = knapsack(maxTime, score, time, selectedItems, study);
    cout << endl << "Maxima nota posible: " << maxGrade << endl;
    cout << "Ejercicios seleccionados: ";
    for (int i = 0; i < selectedItems.size(); ++i) {
        if (selectedItems[i]) {
            cout << i + 1 << " ";
        }
    }

    int choice2;
    cout << endl << "Espero que le haya servido " << endl;
    cout << "Que desea hacer " << endl;
    cout << "1. Pregutar de nuevo" << endl;
    cout << "2. Volver al menu" << endl;
    cout << "3. Salir" << endl;
    cout << endl << "Escoge: ";
    cin >> choice2;
    if (choice2 == 1) {
        choice1();
    } else if (choice2 == 2) {
        menu();
    } else if (choice2 != 3) { 
        cout << endl<< endl<< endl<< endl<< "Esa opción no existe, intentalo de nuevo" << endl;
        menu();
    } else {
        cout << " Vuelva pronto";
    }
}


static void choice2 () {
    bool study = true;
    vector<int> time;
    vector<int> score;
    int minScore;
    int topics;
    cout << "Introduce la cantidad de temas: ";
    cin >> topics;
    for(int i = 1; i <= topics; i++){
        int toTime, toScore;
        cout << endl << "Introduce el tiempo que toma estudiar el tema " << i << ":";
        cin >> toTime;
        cout << endl << "Introduce el puntaje que te asegura estudiar el tema " << i << ":" << endl;
        cin >> toScore;
        time.push_back(toTime);
        score.push_back(toScore);
    }
    cout << "Introduce el puntaje minimo para pasar el examen: ";
    cin >> minScore;

    vector<bool> selectedItems(time.size(), false);
    int maxGrade = knapsack(minScore, score, time, selectedItems, study);
    cout << endl << "Menor tiempo posible: " << maxGrade << endl;
    cout << "Temas seleccionados: ";
    for (int i = 0; i < selectedItems.size(); ++i) {
        if (selectedItems[i]) {
            cout << i + 1 << " ";
        }
    }

    int choice3;
    cout << endl << "Espero que le haya servido " << endl;
    cout << "Que desea hacer " << endl;
    cout << "1. Pregutar de nuevo" << endl;
    cout << "2. Volver al menu" << endl;
    cout << "3. Salir" << endl;
    cout << endl << "Escoge: ";
    cin >> choice3;
    if (choice3 == 1) {
        choice2();
    } else if (choice3 == 2) {
        menu();
    } else if (choice3 != 3) { 
        cout << endl<< endl<< endl<< endl<< "Esa opción no existe, intentalo de nuevo" << endl;
        menu();
    } else {
        cout << " Vuelva pronto";
    }
}

int main() {
    menu();
    return 0;
}