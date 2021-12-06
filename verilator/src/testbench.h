#include <verilated_vcd_c.h>

template<class MODULE> struct TESTBENCH {
  // Need to add a new class variable
  VerilatedVcdC	*m_trace;
  unsigned long	m_tickcount;
  MODULE	*m_core;

  TESTBENCH(void) {
      // According to the Verilator spec, you *must* call
      // traceEverOn before calling any of the tracing functions
      // within Verilator.
      Verilated::traceEverOn(true);
      // Everything else can stay like it was before

      m_trace = nullptr;
      m_core = new MODULE;
      m_tickcount = 0l;
  }

  virtual ~TESTBENCH(void) {
      delete m_core;
      m_core = NULL;
  }

  // Open/create a trace file
  virtual	void	opentrace(const char *vcdname) {
      if (!m_trace) {
          m_trace = new VerilatedVcdC;
          m_core->trace(m_trace, 99);
          m_trace->open(vcdname);
      }
  }

  // Close a trace file
  virtual void	close(void) {
      if (m_trace) {
          m_trace->close();
          m_trace = NULL;
      }
  }

  virtual void	reset(void) {
      m_core->i_reset = 0;
      // Make sure any inheritance gets applied
      this->tick();
      m_core->i_reset = 1;
  }

  virtual void	tick(void) {
      // Make sure the tickcount is greater than zero before
      // we do this
      m_tickcount++;

      // Allow any combinatorial logic to settle before we tick
      // the clk.  This becomes necessary in the case where
      // we may have modified or adjusted the inputs prior to
      // coming into here, since we need all combinatorial logic
      // to be settled before we call for a clk tick.
      //
      m_core->clock = 0;
      m_core->eval();

      //
      // Here's the new item:
      //
      //	Dump values to our trace file
      //
      if(m_trace) m_trace->dump(2*m_tickcount-1);

      // Repeat for the positive edge of the clk
      m_core->clock = 1;
      m_core->eval();
      if(m_trace) m_trace->dump(2*m_tickcount);

      // Now the negative edge
//      m_core->clk = 0;
//      m_core->eval();
      if (m_trace) {
          // This portion, though, is a touch different.
          // After dumping our values as they exist on the
          // negative clk edge ...
//          m_trace->dump(10*m_tickcount+5);
          //
          // We'll also need to make sure we flush any I/O to
          // the trace file, so that we can use the assert()
          // function between now and the next tick if we want to.
          m_trace->flush();
      }
  }

  virtual bool	done(void) { return (Verilated::gotFinish()); }
};