#ifndef CAT_h
#define CAT_h

#include <arduino.h>

class CAT
{
  public:
  	CAT(void);
  	void begin(void);
  	uint8_t available(void);

  	
  private:
  	void execute(void);
  	void send(uint8_t data[], uint8_t num );
};

#endif