#!/bin/bash
function show_time {
    read num
    min=0
    hour=0
    day=0
    if((num>59));
    then
        ((sec=num%60))
        ((num=num/60))
        if((num>59));
        then
            ((min=num%60))
            ((num=num/60))
            if((num>23));
            then
                ((hour=num%24))
                
            else
                ((hour=num))
            fi
        else
            ((min=num))
        fi
    else
        ((sec=num))
    fi
    echo "$hour"h "$min"m "$sec"s
}
show_time 
