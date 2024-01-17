#include<bits/stdc++.h>
using namespace std;
//structura de tip chance cu r=rand c=coloana score= scor
struct chance{
    int r,c,score;
};
//structura ce defineste tabla de joc si o printeaza
struct TicTacToe{
    char player,computer;
    char grid[3][3];
    TicTacToe(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)
            grid[i][j]=' ';
        }
    }
    void print(){
        for(int i=0;i<3;i++){
            if(i) cout<<"--------------\n";
            for(int j=0;j<3;j++){
                if(j) cout<<"|";
                cout<<" ";
                if(grid[i][j]==' ')
                cout<<3*i+j+1;
                else cout<<grid[i][j];
                cout<<" ";  
            }
            cout<<'\n';
        }
    }
    //functie ce asigneaza fiecarui jucator X sau O
    void play(){
        while(true){
            cout<<"Which symbol (X or O)?";
            cin>>player;
            if(player=='X'||player=='O') break;
            else cout<<"That's invalid\n";
        }
        if(player=='X') computer='O';
        else computer='X';
        if(player=='O') computer_move();
        print();
        //functie de afisare a rezultatului final
        while(true){
            player_move();
            print();
            if(win()){
                cout<<"PLAYER WINS!\n";
                return ;
            }
            else if(tie()){
                cout<<"DRAW\n";return;
            }
            cout<<"Computer is making a move\n";
            computer_move();
            print();
            if(win()){
                cout<<"Computer wins\n";
                return;
            }
            else if(tie()){
                cout<<"DRAW\n";
                return;
            }
        }
    }
    //functie de calcul a mutarii playerului (verificarea validitatii miscarii)
    void player_move(){
        while(true){
            cout<<"Enter an empty cell(1-9):";
            int cell;cin>>cell;
            int r=(cell-1)/3;
            int c=(cell-1)%3;
            if(cell>=1&&cell<=9&&grid[r][c]==' '){
                grid[r][c]=player;
                break;
            }
        }
    }
    //functie de verificare a castigului 
    bool win(){
        int win_states[8][3]={{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7}};
        for(int i=0;i<8;i++){
            bool win=true;
            //first_r si first_c reprezinta primul element din fiecare win_states
            int first_r=(win_states[i][0]-1)/3;
            int first_c=(win_states[i][0]-1)%3;
            //r,c trec prin fiecare element al fiecarui win_states
            for(int j=0;j<3;j++){
                int r=(win_states[i][j]-1)/3;
                int c=(win_states[i][j]-1)%3;
                if(grid[first_r][first_c]==' '||grid[first_r][first_c]!=grid[r][c]) 
                //conditia de pierdere e ca sa avem spatii sau sa avem elementul oponentului
                win=false;
            }
            if(win) return true;
        }
        return false;
    }
    //functie de verificare a egalitatii
    bool tie(){
        if(win()) return false;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==' ') return false;
            }
        }
        return true;
    }
    //functia de mutare pentru computer 
    void computer_move(){
        chance best_move=minimax(1);
        grid[best_move.r][best_move.c]=computer;
    }
    //functia de min_max
    chance minimax(bool maximizing_player=true){
        //initializeaza structura cu valoarea celei mai bune miscari
        chance best_move;
        //verifica daca jocul a fost castigat, pierdut sau egalitate si da fiecarui final valoarea corespunzatoare
        if(win()){
            if(maximizing_player){
                best_move.score=-1;
            }
            else best_move.score=1;
            return best_move;
        }
        if(tie()){
            best_move.score=0;
            return best_move;
        }
        //initializam miscarea best_move in functtie daca minimalizam sau maximalizam playerul(uman)
        best_move.score=maximizing_player?-1e5:1e5;
        //trecem prin fiecare celula si verificam daca e goala
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==' '){
                    //se incearca mutarea pentru playerul curent, maximizand sau minimizand
                    grid[i][j]=maximizing_player?computer:player;
                    //apel recursiv pentru a determina valoarea mutarii
                    chance board_state=minimax(maximizing_player^1);
                    //update best move daca maximizam...mutarea curenta are valoare mai mare decat best-ul existrnt atunci 
                    //valoarea curenta devine noul best
                    if(maximizing_player){
                        if(board_state.score>best_move.score){
                            best_move.score=board_state.score;
                            best_move.r=i;
                            best_move.c=j;
                        }
                    }
                    //update best move daca minimizam...mutarea curenta are valoare mai mica decat best-ul existrnt atunci 
                    //valoarea curenta devine noul best
                    else{
                        if(board_state.score<best_move.score){
                            best_move.score=board_state.score;
                            best_move.r=i;
                            best_move.c=j;
                        }
                    }
                    grid[i][j]=' ';
                }
            }
        }
        return best_move;
    }
};
//main...se creaza o instanta de joc 
int main(){
    TicTacToe game;
    game.play();
    return 0;
}


