#include <stdio.h>
#include <string.h>
#include <math.h>

int classOfid[1005], lastinclass[15], outinclass[15], queue[12][1005], status[11];

int main() {
    int Nc, Ns;
    scanf("%d %d", &Nc, &Ns);
    int tempc, tempid;
    for(int i=0; i<Ns; i++) {
        scanf("%d %d", &tempc, &tempid);
        classOfid [tempid] = tempc;
    }
    int inpid;
    char inpch;
    int id, i ,len, lastqueue = 1, queueout = 1;
    while(inpch!='X') {
        scanf("%c", &inpch);
        if(inpch == 'E') {
            scanf("%d", &id);
                if(status[classOfid[id]]) {
                    // printf("add id:%d index:%d\n", id, lastinclass[classOfid[id]]);
                    queue[classOfid[id]] [lastinclass[classOfid[id]]] = id;
                    lastinclass[classOfid[id]]++;
                }
                else {
                    status[classOfid[id]]=lastqueue;
                    queue[classOfid[id]] [lastinclass[classOfid[id]]] = id;
                    lastinclass[classOfid[id]]++;
                    lastqueue++;
                }
                // printf("nextqueue: %d\n" ,lastqueue);
               
        }
        else if(inpch == 'D') {
            int classtemp=0,tempid;
            while(status[classtemp]!=queueout && classtemp<11) {
                classtemp++;
            }
            // printf("class:%d lastin:%d outin:%d\n", classtemp, lastinclass[classtemp], outinclass[classtemp]);
            if(lastinclass[classtemp] == outinclass[classtemp]){
                printf("empty\n");
            }
            else {
                int tempid=queue[classtemp][outinclass[classtemp]];
                printf("%d\n", tempid);
                outinclass[classtemp]++;
                if(lastinclass[classtemp] == outinclass[classtemp]){
                    status[classOfid[tempid]] = 0;

                    queueout++;
                }
            }
        }
    }
    printf("0");
}