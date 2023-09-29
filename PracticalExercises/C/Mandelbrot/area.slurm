#!/bin/bash

# Slurm job options (job-name, compute nodes, job time)
#SBATCH --job-name=Mandelbrot
#SBATCH --time=0:05:0
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --tasks-per-node=1  # number of MPI ranks
#SBATCH --cpus-per-task=128

# Replace [budget code] below with your budget code (e.g. ta123)
#SBATCH --account=ta119
# We use the "standard" partition as we are running on CPU nodes
#SBATCH --partition=standard
#SBATCH --qos=standard

# Propagate the cpus-per-task setting from script to srun commands
#    By default, Slurm does not propagate this setting from the sbatch
#    options to srun commands in the job script. If this is not done,
#    process/thread pinning may be incorrect leading to poor performance
export SRUN_CPUS_PER_TASK=$SLURM_CPUS_PER_TASK

#   We want one thread per physical core
export OMP_PLACES=cores
#   Bind threads to cores in order
export OMP_PROC_BIND=close


for t in 1 2 4 8 16 32 64 128
do
    export OMP_NUM_THREADS=$t

    # Launch the parallel job
    #   Additional srun options to pin one thread per physical core
    srun --hint=nomultithread ./area
done
