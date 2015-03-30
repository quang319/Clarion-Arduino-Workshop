library(DiagrammeR)

#This is the flow chart for Program #1
Program1 <-"
           graph TD;
          A[Setup pin 13] --> B[Turn On LED];
          B --> C[Delay 1s];
          C --> D[Turn Off LED];
          D --> B
           "
mermaid(Program1)


# This is the flow chart for Program #2
library(DiagrammeR)
Program2 <-"
graph TD
 A[Establish Serial Comm] --> B[Setup pin 13]
  B --> IF1{Max Score not reached?}
  IF1 --> |No|ELSE1_A[Print congratz msg]
  ELSE1_A --> ELSE1_B[Turn On LED]
  IF1 --> |Yes|IF1_A[Blink LED]
  IF1_A --> IF2{Double points reached?}
  IF2 --> |NO|IF2_A[Increment Double Score Counter];
  ELSE2_A --> ELSE2_B[DOUBE CURRENT SCORE];
  ELSE2_B --> C[Print Score];
  IF2_A --> IF2_B[Increment Score];
  IF2 --> |YES|ELSE2_A[Clear Double Score Counter];
  IF2_B --> C;
  C --> IF1;

"
mermaid(Program2)
