#pragma once 

#define __Trace(...) printf("\nfile[%s]line[%d]func[%s]",__FILE__,__LINE__,__FUNCTION__);printf(__VA_ARGS__);