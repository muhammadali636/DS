#include "graph.h"

/*
 * A basic menu based structure has been provided
 */

int main(int argc, char *argv[])
{
    //command line check.
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    //read graph
    Graph *graph = readGraph(argv[1]); //assuume its read fine. 

    int choice; 
    int startVertex = 1;

    do
    {

        // Display the options
        prompt();

        // Get user input
        printf("Enter your choice: ");
        scanf("%d", &choice);

        /*
         * You will need to add all the cases here.
         * Call the relevant functions in each case.
         * Make sure to handle invalid inputs or edge cases.
         */

        switch (choice) {
            case 1:
                // Code for case 1
                displayAdjacencyList(graph);
                break; //avoid fall through.

            case 2:
                //BFS
                bfs(graph, startVertex - 1);
                break;
            
            case 3:
                dfs(graph, startVertex - 1);
                break;
            
            case 4:
                dijkstra(graph, startVertex - 1);
                break;
            
            case 5: //to quit.
                printf("Exiting the program.\n");
                freeGraph(graph);
                return 0;

            default:
                // Code for default case
                //printf invalid choice.
                break;
        }

    } while (true);

    freeGraph(graph);
    return 0;
}
