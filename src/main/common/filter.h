/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#define DELTA_MAX_SAMPLES 12

typedef struct filterStatePt1_s {
	float state;
	float RC;
	float constdT;
} filterStatePt1_t;

/* this holds the data required to update samples thru a filter */
typedef struct biquad_s {
    float b0, b1, b2, a1, a2;
    float d1, d2;
} biquad_t;

float applyBiQuadFilter(float sample, biquad_t *state);
float filterApplyPt1(float input, filterStatePt1_t *filter, float f_cut, float dt);
int32_t filterApplyAverage(int32_t input, uint8_t averageCount, int32_t averageState[DELTA_MAX_SAMPLES]);
float filterApplyAveragef(float input, uint8_t averageCount, float averageState[DELTA_MAX_SAMPLES]);
void BiQuadNewLpf(float filterCutFreq, biquad_t *newState, uint32_t refreshRate);
