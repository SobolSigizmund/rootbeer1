#ifndef NAN
#include <math_constants.h>
#define NAN CUDART_NAN
#endif

#ifndef INFINITY
#include <math_constants.h>
#define INFINITY CUDART_INF
#endif

__shared__ size_t m_Local[3];
texture<int> m_Cache;
__shared__ int m_ScratchPad;

__device__
int getThreadId(){
  return blockIdx.x * blockDim.x + threadIdx.x;
}

__device__
void synchthreads(){
  __syncthreads();
}