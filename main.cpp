/* Program to check whether a set of char is inside another.
 * Author: Javier Fadel.
 * Modified: 5 Oct. 2022. */
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

/* Data gejala:
 * [a] Masuk angin.
 * [b] Sakit kepala tapi setengah.
 * [c] Suhu tubuh panas.
 * [d] Mata lelah.
 * [e] Mata berkunang-kunang.
 * [f] Pegal.
 * [g] Tidak ada semangat hidup.
 * [h] Pilek.
 * [i] Batuk.
 * [j] Bersin.
 *
 * Data penyakit:
 * [a] Masuk angin.
 * [b] Flu.
 * [c] Kurang duit, harap bersabar.
 * [d] Batuk
 * [e] Kelelahan.
 * */

// Function to check if a set of array is inside another.
bool contains(array<char, 3> gejalaInput, array<char, 3> gejalaPenyakit) {
    int counter = 0;
    for(int i = 0; i < gejalaInput.size(); i++) {
        // For every current value, check whether the value is inside a symptoms array.
        // Find current gejalaPenyakit value to gejalaInput, from begin to end.
        if (find(gejalaInput.begin(), gejalaInput.end(), gejalaPenyakit[i]) != gejalaInput.end()) {
            // If the value is match, track the similarities with counter variable.
            counter++;
        }
    }
    // If the match value is more than two, confirm disease.
    return (counter >= 2);
}

// Main function.
int main() {
    // Symptoms data: set of array (could be more effective).
    // 'Mini database': contain set of character. Could it be more effective?
    // Perhaps with multidimensional array.
    array<char, 3> gejalaMasukAngin{'a', 'c', 'h'};
    array<char, 3> gejalaFlu{'b', 'g', 'h'};
    array<char, 3> gejalaKurangDuit{'a', 'd', 'g'};
    array<char, 3> gejalaBatuk{'b', 'i', 'j'};
    array<char, 3> gejalaKelelahan{'b', 'e', 'f'};
    array<char, 3> gejalaInput{};

    vector<vector<char>> charArr{
            {'a', 's', 'd'},
            {'v', 'c', 's'},
            {'f', 'g', 'h'}
    };

    // Display symptoms: symptoms are displayed and indexed with characters.
    cout << "Data gejala:\n";
    cout << "[a] Masuk angin\n";
    cout << "[b] Sakit kepala tapi setengah\n";
    cout << "[c] Suhu tubuh panas\n";
    cout << "[d] Mata lelah\n";
    cout << "[e] Mata berkunang-kunang\n";
    cout << "[f] Pegal\n";
    cout << "[g] Tidak ada semangat hidup\n";
    cout << "[h] Pilek\n";
    cout << "[i] Batuk\n";
    cout << "[j] Bersin\n";

    // Input symptoms: saved on a static array, perhaps use vector?
    cout << "Input gejala penyakit (maks. 3, a-h)\n";
    for (int i = 0; i < gejalaInput.size(); ++i) {
        cout << "Gejala ke-" << i + 1 << ":";
        cin >> gejalaInput[i];
    }

    // Lowered all input data: to match correctly.
    for (char & i : gejalaInput) {
        // Replace current value with lowered current value.
        i = tolower(i);
    }

    // Calculate: call contain function.
    // Contain function return a boolean value, passed it to the conditional.
    // If the value is true, confirm disease. Repeat until all the disease covered.
    // Perhaps use switch?
    if (contains(gejalaInput, gejalaMasukAngin)) {
        cout << "Anda demam. Segera istirahat dan periksa ke dokter bila gejala berlanjut.\n";
    } else if (contains(gejalaInput, gejalaBatuk)) {
        cout << "Anda batuk. Hindari makanan berminyak dan merokok.\n";
    } else if (contains(gejalaInput, gejalaKurangDuit)) {
        cout << "Anda kurang duit. Segera cari secepatnya, atau anda akan merana.\n";
    } else if (contains(gejalaInput, gejalaFlu)) {
        cout << "Anda terjangkit flu. Segera minum obat dengan paracetamol dan istirahat yang cukup.\n";
    } else if (contains(gejalaInput, gejalaKelelahan)) {
        cout << "Anda kelelahan. Segerakan istirahat yang cukup.\n";
    } else {
        cout << "Anda tidak mengidap penyakit apapun.\n";
    }

    return 0;
}
