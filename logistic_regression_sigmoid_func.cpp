#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

// Sigmoid function
double sigmoid( double z ){
    return 1.0 / ( 1.0 + exp( -z ) );
}

// Compute the loss function (binary cross-entropy)
double compute_loss( const std::vector<double>& y_true, const std::vector<double>& y_pred ){
    double loss = 0.0;
    for( size_t i = 0 ; i < y_true.size() ; i++ ){
        loss += y_true[ i ]*log( y_pred[ i ] ) + ( 1 - y_true[ i ] ) * log( 1 - y_pred[ i ] );
    }
    return -loss / y_true.size();
}

// Train logistic regression using gradient descent
void train_logistic_regression( std::vector<std::vector<double>>& X, 
                               std::vector<double>& y, 
                               std::vector<double>& weights, 
                               double& bias, 
                               double learning_rate, 
                               int epochs ){
    int m = X.size();       // Number of samples
    int n = X[ 0 ].size();    // Number of features

    for( int epoch = 0 ; epoch < epochs ; epoch++) {
        std::vector<double> y_pred( m, 0.0 );
        double dw[ n ] = { 0 };
        double db = 0.0;

        // Forward pass
        for( int i = 0 ; i < m; i++ ){
            double linear_output = bias;
            for( int j = 0 ; j < n ; j++ ){
                linear_output += X[ i ][ j ] * weights[ j ];
            }
            y_pred[ i ] = sigmoid( linear_output );
        }

        // Compute gradients
        for( int i = 0 ; i < m ; i++ ){
            double error = y_pred[i] - y[i];
            for( int j = 0 ; j < n ; j++ ){
                dw[j] += X[i][j] * error / m;
            }
            db += error / m;
        }

        // Update weights and bias
        for( int j = 0 ; j < n ; j++){
            weights[j] -= learning_rate * dw[j];
        }
        bias -= learning_rate * db;

        // Print loss every 100 epochs
        if( epoch % 100 == 0 ){
            double loss = compute_loss( y, y_pred );
            std::cout << "Epoch " << epoch << " - Loss: " << loss << std::endl;
        }
    }
}

// Main function
int main(){
    // Example dataset: 4 samples, 2 features
    std::vector<std::vector<double>> X = {
        {0, 0}, {0, 1}, {1, 0}, {1, 1}
    };
    
    std::vector<double> y = { 0, 0, 0, 1 }; // AND gate output
    
    int n_features = X[ 0 ].size();
    std::vector<double> weights( n_features, 0.0 ); // Initialize weights to 0
    double bias = 0.0;
    double learning_rate = 0.1;
    int epochs = 1000;

    // Train logistic regression model
    train_logistic_regression( X, y, weights, bias, learning_rate, epochs );

    // Print final weights and bias
    std::cout << "Final Weights: ";
    for( double w : weights ){
        std::cout << w << " ";
    }
    std::cout << "\nFinal Bias: " << bias << std::endl;

    return 0;
}
