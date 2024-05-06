#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Relation {
public:
    bool isRflx() {
        return digit1 == digit2;
    }

    void makeRelation(int d1, int d2) {
        digit1 = d1;
        digit2 = d2;
    }

    int getD1() {
        return digit1;
    }

    int getD2() {
        return digit2;
    }

private:
    int digit1;
    int digit2;
};

bool isReflexive(string set, vector<Relation> vec) {
    for(char i : set) {
        bool reflexive = false;
        for(Relation r: vec) {
            if((i - '0') == r.getD1() && r.isRflx()) { // convert set[i] to int before comparison
                reflexive = true;
                break;
            }
        }
        if(!reflexive) return false;
    }
    return true;
}

bool isIrreflexive(string set, vector<Relation> vec) {
    for(char i : set) {
        for(Relation r: vec) {
            if((i - '0') == r.getD1() && r.isRflx()) {
                return false;
            }
        }
    }
    return true;
}

bool isTransitive(vector<Relation> vec, map<pair<int, int>, bool> relationMap) {
    for(Relation r1 : vec) {
        for(Relation r2 : vec) {
            if(r1.getD2() == r2.getD1() && !relationMap[{r1.getD1(), r2.getD2()}]) {
                return false;
            }
        }
    }
    return true;
}

bool isSymmetric(vector<Relation> vec, map<pair<int, int>, bool> relationMap) {
    for(Relation r1 : vec) {
        if(relationMap[{r1.getD1(), r1.getD2()}] && !relationMap[{r1.getD2(), r1.getD1()}]) {
            return false;
        }
    }
    return true;
}

bool isAntisymmetric(vector<Relation> vec, map<pair<int, int>, bool> relationMap) {
    for(Relation r1 : vec) {
        for(Relation r2 : vec) {
            if(r1.getD1() == r2.getD2() && r1.getD2() == r2.getD1()) {
                if(r1.getD1() != r1.getD2()) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    string set, relations, setDigits, relationsDigits;
    bool rflx, iflx, tran, symm, anti;
    int input;

    vector<Relation> vecRelations;
    map<pair<int, int>, bool> relationMap;

    cout << "Enter your set" << endl;
    getline(cin, set);

    cout << "Enter the relations" << endl;
    getline(cin, relations);

    // Remove unwanted characters from set
    for(char c : set) {
        if (c != '{' && c != '}' && c != ',' && c != ' ') {
            setDigits += c;
        }
    }

    // Remove unwanted characters from relations
    for(char c : relations) {
        if (c != '{' && c != '}' && c != '(' && c != ')' && c != ',' && c != ' ') {
            relationsDigits += c;
        }
    }

    for(int i = 0; i < relationsDigits.length(); i += 2) {
        int d1 = relationsDigits[i] - '0'; // Convert char to int
        int d2 = relationsDigits[i + 1] - '0'; // Convert char to int
        Relation r;
        r.makeRelation(d1, d2);
        vecRelations.push_back(r);
    }

    for(Relation r : vecRelations) { // create map containing all relations for O(1) runtime
        relationMap[{r.getD1(), r.getD2()}] = true;
    }

    cout << "What do you want to check for?\n1. Reflexivity O(mn) \n2. Irreflexivity O(mn) \n3. Transitivity O(n^2) \n4. Symmetry O(n) \n5. Antisymmetry O(n^2) \n6. Equivalence Relation O(n^2) \n7. Partially-ordered Set O(n^2) \n8. Check All O(n^2) \n9. Exit" << endl;

    rflx = isReflexive(setDigits, vecRelations);
    iflx = isIrreflexive(setDigits, vecRelations);
    tran = isTransitive(vecRelations, relationMap);
    symm = isSymmetric(vecRelations, relationMap);
    anti = isAntisymmetric(vecRelations, relationMap);

    while(true) {
        cin >> input;

        if(input == 1) {
            if(rflx) cout << "This relation is reflexive" << endl;
            else cout << "This relation is not reflexive" << endl;
        }
        else if(input == 2) {
            if(iflx) cout << "This relation is irreflexive" << endl;
            else cout << "This relation is not irreflexive" << endl;
        }
        else if(input == 3) {
            if(tran) cout << "This relation is transitive" << endl;
            else cout << "This relation is not transitive" << endl;
        }
        else if(input == 4) {
            if(symm) cout << "This relation is symmetric" << endl;
            else cout << "This relation is not symmetric" << endl;
        }
        else if(input == 5) {
            if(anti) cout << "This relation is antisymmetric" << endl;
            else cout << "This relation is not antisymmetric" << endl;
        }
        else if(input == 6) {
            if(rflx && tran && symm) cout << "This relation is an equivalence relation" << endl;
            else cout << "This relation is not an equivalence relation" << endl;
        }
        else if(input == 7) {
            if(rflx && tran && anti) cout << "This relation is a partially-ordered set" << endl;
            else cout << "This relation is not a partially-ordered set" << endl;
        }
        else if(input == 8) {
            vector<string> properties;
            
            if(rflx || iflx || tran || symm || anti) { // if relation has at least one property true
                if(rflx) properties.push_back("reflexive");
                if(iflx) properties.push_back("irreflexive");
                if(tran) properties.push_back("transitive");
                if(symm) properties.push_back("symmetric");
                if(anti) properties.push_back("antisymmetric");

                cout << "This relation is ";
                for(int i = 0; i < properties.size(); i++) {
                    cout << properties[i];
                    
                    if(properties.size() > 2 && i != properties.size()-1) cout << ", "; // format text
                    if(properties.size() == 2) cout << " ";
                    if(i == properties.size()-2) cout << "and ";
                }
                cout << endl;
            }
            else cout << "This relation does not satisfy any of the listed properties" << endl;
        }
        else if(input == 9) {
            return 1;
        }
    }
    return 0;
}
