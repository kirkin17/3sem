int main() {    
    string sudoku_easy = "000079065000003002005060093340050106000000000608020059950010600700600000820390000";
    sudoku sudo_easy = sudoku(sudoku_easy);
    sudo_easy.solve();

    string sudoku_hard = "4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4......";
    sudoku sudo_hard = sudoku(sudoku_hard);
    sudo_hard.solve();
}