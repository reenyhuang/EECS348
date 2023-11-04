# Set the base image to use
FROM gcc:latest
# Copy the C program into the container
COPY hello.c .
# Compile the C program
RUN gcc -o hello hello.c
# Set the command to run when the container starts
CMD ["./hello"]