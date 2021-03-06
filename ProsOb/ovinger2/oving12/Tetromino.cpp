#include "Tetromino.h"
    
const map<TetrominoType, vector<vector<int>>> initialMatrixMap {

    {
    TetrominoType::J,
        {
        {0, 0, 0},
        {1, 1, 1},
        {0, 0, 1}
        }
    },
    { 
    TetrominoType::L, 
        {
        {0, 0, 0},
        {1, 1, 1},
        {1, 0, 0}
        }
    },
    { 
    TetrominoType::S, 
        {
        {0, 1, 1},
        {0, 1, 0},
        {1, 1, 0}
        }
    },
    { 
    TetrominoType::T, 
        {
        {0, 1, 0},
        {1, 1, 1},
        {0, 0, 0}
        }
    },
    { 
    TetrominoType::Z, 
        {
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 1}
        }
    },
    {
    TetrominoType::O, 
        {
        {1, 1},
        {1, 1}
        }
    },
    {
    TetrominoType::I, 
        {
        //Denne er representert som en 6x6 matrise for å få en bedre rotasjonsfunksjonalitet
        {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
        }
    }
};

Tetromino::Tetromino(Point startingPoint, TetrominoType tetType): 
    matrixSize{static_cast<int>(initialMatrixMap.at(tetType).size())},
    topLeftCorner{startingPoint}
    //blockMatrix(matrixSize,(vector<TetrominoType>(matrixSize, TetrominoType::NONE)))
{
    
}

void Tetromino::rotateCounterClockwise() {
    //Første rotasjon, med hensyn på diagonalen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < row; column++){
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }

    //Andre rotasjon, med hensyn på den midtre raden
    for(int row = 0; row < matrixSize/2; row++){
        for(int column = 0; column < matrixSize; column++){
            std::swap(blockMatrix[row][column], blockMatrix[matrixSize-row-1][column]);
            
        }
    }
}

void Tetromino::rotateClockwise() {
    //Første rotasjon, med hensyn på diagonalen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < row; column++){
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }
     
    //Andre rotasjon, med hensyn på den midtre kolonnen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < matrixSize/2; column++){
            std::swap(blockMatrix[row][column], blockMatrix[row][matrixSize-column-1]);
        }
    }
}
