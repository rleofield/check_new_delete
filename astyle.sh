#!/bin/bash
 
#ASTYLE="astyle --style=java --add-brackets --indent-col1-comments --break-blocks --pad-oper --pad-paren-in --unpad-paren --indent-namespaces --align-pointer=type --align-reference=type --convert-tabs"
ASTYLE="astyle -s3  --style=java --add-brackets --indent-col1-comments --break-blocks --pad-oper --pad-paren-in --unpad-paren --indent-namespaces --align-pointer=type --convert-tabs"

${ASTYLE} -r "src/*.cpp"
${ASTYLE} -r "src/*.h"

#${ASTYLE} -r "SDK_Includes/*.cpp"
#${ASTYLE} -r "SDK_Includes/*.h"


