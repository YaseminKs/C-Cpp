#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

#define INPUT_NODES 3
#define HIDDEN_NODES 4
#define OUTPUT_NODES 2
#define LEARNING_RATE 0.1

using namespace std;

struct NeuralNetwork{
    vector<vector<double>> weightsIH;
    vector<vector<double>> weightsHO;
    vector<double> hidden;
    vector<double> output;

    NeuralNetwork(){
        weightsIH.resize( INPUT_NODES, vector<double>( HIDDEN_NODES ) );
        weightsHO.resize( HIDDEN_NODES, vector<double>( OUTPUT_NODES ) );
        hidden.resize( HIDDEN_NODES );
        output.resize( OUTPUT_NODES );

        for( auto &row : weightsIH )
            for( auto &w : row )
                w = ( ( double )rand() / RAND_MAX ) * 2 - 1;

        for( auto &row : weightsHO )
            for( auto &w : row )
                w = ( ( double )rand() / RAND_MAX ) * 2 - 1;
    }

    double sigmoid( double x ){
        return 1.0 / ( 1.0 + exp( -x ) );
    }

    double sigmoidDerivative( double x ){
        return x * ( 1 - x );
    }

    void forwardPass( const vector<double> &input ){
        for( int i = 0 ; i < HIDDEN_NODES ; i++ ){
            hidden[i] = 0;
            for( int j = 0 ; j < INPUT_NODES ; j++ )
                hidden[i] += input[j] * weightsIH[j][i];
            hidden[i] = sigmoid( hidden[i] );
        }

        for( int i = 0 ; i < OUTPUT_NODES ; i++ ){
            output[i] = 0;
            for( int j = 0 ; j < HIDDEN_NODES ; j++ )
                output[i] += hidden[j] * weightsHO[j][i];
            output[i] = sigmoid( output[i] );
        }
    }

    void backwardPass( const vector<double> &input, const vector<double> &target ){
        vector<double> outputErrors( OUTPUT_NODES );
        vector<double> outputDeltas( OUTPUT_NODES );

        for( int i = 0 ; i < OUTPUT_NODES ; i++ ){
            outputErrors[i] = target[i] - output[i];
            outputDeltas[i] = outputErrors[i] * sigmoidDerivative( output[i] );
        }

        vector<double> hiddenErrors( HIDDEN_NODES, 0 );
        vector<double> hiddenDeltas( HIDDEN_NODES );

        for( int i = 0 ; i < HIDDEN_NODES ; i++ ){
            for( int j = 0 ; j < OUTPUT_NODES ; j++ )
                hiddenErrors[i] += outputDeltas[j] * weightsHO[i][j];

            hiddenDeltas[i] = hiddenErrors[i] * sigmoidDerivative( hidden[i] );
        }

        for( int i = 0 ; i < HIDDEN_NODES ; i++ )
            for( int j = 0 ; j < OUTPUT_NODES ; j++ )
                weightsHO[i][j] += LEARNING_RATE * outputDeltas[j] * hidden[i];

        for( int i = 0 ; i < INPUT_NODES ; i++ )
            for( int j = 0 ; j < HIDDEN_NODES ; j++ )
                weightsIH[i][j] += LEARNING_RATE * hiddenDeltas[j] * input[i];
    }
};

int main(){
    srand( time( 0 ) );
    NeuralNetwork nn;

    vector<vector<double>> inputs = { { 1.0, 0.5, -1.5 }, { 0.2, -0.3, 0.8 } };
    vector<vector<double>> targets = { { 0.1, 0.9 }, { 0.8, 0.2 } };

    for( int epoch = 0 ; epoch < 1000 ; epoch++ ){
        for( size_t i = 0 ; i < inputs.size() ; i++ ){
            nn.forwardPass( inputs[i] );
            nn.backwardPass( inputs[i], targets[i] );
        }
    }

    cout << "Training Completed\n";
    return 0;
}
