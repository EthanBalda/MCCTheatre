#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 10;
const int COLS = 30;
int ticketsSold = 0;

//methods
void initializeSeatingChart(char seatingChart[][COLS]){

  for (int i = 0; i < ROWS; i++)
    for(int j = 0; j < COLS; j++)
      seatingChart[i][j] = '*';


}

void printSeatingChart(char seatingChart[][COLS]){

    cout << "\n         ";
    for (int i = 0; i < COLS / 2 - 3; i++) cout << " ";
    cout << "Seats";
    for (int i = 0; i < COLS / 2 - 3; i++) cout << " ";
    cout << "\n         ";
    for (int i = 1; i <= COLS; i++) {
      cout << (i % 10);
    }
    cout << endl;

  
 
  cout << endl;
   for (int i = 0; i < ROWS; i++){
    cout << "Row " << left << setw(5) << i+1;
     for(int j = 0; j < COLS; j++)
       cout << seatingChart[i][j];
     cout << endl;
   }
  cout << endl;

}

void initializePrices(double prices[ROWS]){

  for(int i = 1; i <= ROWS; i++){
    cout << "What is the price of row " << i << "? $";
    cin >> prices[i-1];
  }
}

bool reserveSeats(char seatingChart[][COLS], int row, int seat, int numSeats){

  if(row < 1 or row > ROWS or seat < 1 or seat > COLS or seat+numSeats > COLS+1)
    return false;

  row--; seat--;
  bool noTicketsSold = true;
  for(int i = seat; i < seat+numSeats; i++)
    if(seatingChart[row][i] != '*'){
      noTicketsSold = false;
      break;
      }
    if (noTicketsSold){
      for(int i = seat; i < seat+numSeats; i++)
        seatingChart[row][i] = 'X';
      ticketsSold++;
    }
  return noTicketsSold;    
}

int main() {
cout << "~~~WELCOME TO THE MIRACOSTA THEATRE~~~\n\n";
  double prices[ROWS];
  initializePrices(prices);
  char seatingChart[ROWS][COLS];
  initializeSeatingChart(seatingChart);
  printSeatingChart(seatingChart);

  int row, seat, numSeats;
  double price, total = 0;
  bool noTicketsSold;
  while (ticketsSold < ROWS * COLS) {
    cout << "\n~~~Purchase Seats~~~\n"
         << "Which row? ";
    cin >> row;
    cout << "Which seat #";
    cin >> seat;
    cout << "How many seats? ";
    cin >> numSeats;
    noTicketsSold = reserveSeats(seatingChart, row, seat, numSeats);
    if (noTicketsSold) {
      price = prices[row - 1] * numSeats;
      total += price;
      cout << numSeats << " tickets successfully purchased!\n"
           << fixed << setprecision(2)
           << "Purchase Amount $" << price << endl
           << "Total Revenue $" << total << endl;
    } else {
      cout << "Sorry, your request could not be completed.\n";
    }
    printSeatingChart(seatingChart);
  }
}
