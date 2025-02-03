#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#define POP_SIZE 100  
#define CHROMO_LENGTH 16  
#define MUTATION_RATE 0.01  
#define GENERATIONS 100  

using namespace std;

struct Individual{
    int chromosome;
    int fitness;

    Individual(){
        chromosome = rand() % ( 1 << CHROMO_LENGTH );
        fitness = calculateFitness();
    }

    int calculateFitness(){
        int count = 0;
        for( int i = 0 ; i < CHROMO_LENGTH ; i++ )
            if( chromosome & ( 1 << i ) ) count++;
        return count;
    }
};

bool compareFitness( const Individual &a, const Individual &b ){
    return a.fitness > b.fitness;
}

void mutate( Individual &ind ){
    for( int i = 0 ; i < CHROMO_LENGTH ; i++ )
        if( ( rand() / ( float )RAND_MAX ) < MUTATION_RATE )
            ind.chromosome ^= (1 << i);  
}

Individual crossover( Individual &p1, Individual &p2 ){
    int crossover_point = rand() % CHROMO_LENGTH;
    int mask = ( 1 << crossover_point ) - 1;
    Individual offspring;
    offspring.chromosome = ( p1.chromosome & mask ) | ( p2.chromosome & ~mask );
    offspring.fitness = offspring.calculateFitness();
    return offspring;
}

int main(){
    srand( time( 0 ) );
    vector<Individual> population( POP_SIZE );

    for( int gen = 0 ; gen < GENERATIONS ; gen++ ){
        sort( population.begin(), population.end(), compareFitness );
        vector<Individual> new_population;

        for( int i = 0 ; i < POP_SIZE / 2 ; i++ ){
            Individual offspring = crossover( population[i], population[i + 1] );
            mutate( offspring );
            new_population.push_back( offspring );
        }

        population = new_population;
        cout << "Generation " << gen << " Best Fitness: " << population[0].fitness << endl;
    }

    return 0;
}
