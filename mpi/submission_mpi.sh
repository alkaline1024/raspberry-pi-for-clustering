#!/bin/bash
#SBATCH -o matrix-%j.out
#SBATCH -e matrix-%j.err
cd $SLURM_SUBMIT_DIR
mpirun a.out