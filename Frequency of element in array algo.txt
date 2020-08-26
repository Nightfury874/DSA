STEP 1: START
STEP 2: INITIALIZE arr[] ={1, 2, 8, 3, 2, 2, 2, 5, 1 }.
STEP 3: length = sizeof(arr)/sizeof(arr[0])
STEP 4: DEFINE fr[length].
STEP 5: SET visited = -1.li>
STEP 6: SET i= 0. REPEAT STEP 7 to STEP 12 UNTIL i<length.
STEP 7: SET count = 1
STEP 8: SET j =0. REPEAT STEP 9 and STEP 10 UNTIL j<length.
STEP 9: if(arr[i]==arr[j]) then
              count++
              fr[j] =visited
STEP 10: j= j+1.
STEP 11: if(fr[i]!=visited) then
              fr[i]=count
STEP 12: i=i+1
STEP 13: PRINT "------------"
STEP 14: PRINT "Element | Frequency"
STEP 15: PRINT "-------------"
STEP 16: SET i=0. REPEAT STEP 17 to STEP 18 UNTIL i<length.
STEP 17: if(fr[i]!=visited) then
              PRINT arr[i]
              PRINT | PRINT fr[i]
STEP 18: i=i+1.
STEP 19: PRINT "-------------"
STEP 20: RETURN 0.
STEP 21: END
