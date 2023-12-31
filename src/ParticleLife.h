#pragma once

#include <raylib.h>
#include <raymath.h>

#include <vector>

/* NOTES
    - the infuential radius of a particle (outer radius) is 1.0f
    - resistance of a particle is scaled by the inner radius
    - a negative attraction value repulses
    - the simulations grid is the +/- of the bounds, particles will bounce of the edges
    - certain attributes are public to allow them to be manipulated using the ui
*/


class ParticleLife
{
 public:

    ParticleLife();
    ~ParticleLife();

    void init(int count, int size);
    void update();
    
    int* types;
    Vector2* positions;
    Vector2* velocities;

    int** gridCounts;
    std::vector<int>** gridIndexes;
    std::vector<int>**** neighborhoods;

    float step;
    float resistance;
    float innerRadii[3];
    float attractions[3][3];
    Color colours[3];

    int count;
    int size;
    float bounds;

 private:

    int rowColHash(float coord);

    void mapNeighborhoods();
    void calculateForces();
    void applyForces();

};


