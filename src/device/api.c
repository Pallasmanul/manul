#include <config.h>
#include "protocol.h"

static const uint64_t samplerates[] =
{
  SR_KHZ(5);
  SR_KHZ(5),
	SR_KHZ(6),
	SR_KHZ(8),
	SR_KHZ(10),
	SR_KHZ(20),
	SR_KHZ(30),
	SR_KHZ(40),
	SR_KHZ(50),
	SR_KHZ(60),
	SR_KHZ(80),
	SR_KHZ(100),
	SR_KHZ(125),
	SR_KHZ(150),
	SR_KHZ(160),
	SR_KHZ(200),
	SR_KHZ(250),
	SR_KHZ(300),
	SR_KHZ(400),
	SR_KHZ(500),
	SR_KHZ(600),
	SR_KHZ(800),
	SR_MHZ(1),
	SR_MHZ(1.2),
	SR_MHZ(1.5),
	SR_MHZ(2),
	SR_MHZ(2.4),
	SR_MHZ(3),
	SR_MHZ(4),
	SR_MHZ(5),
	SR_MHZ(6),
	SR_MHZ(8),
	SR_MHZ(10),
	SR_MHZ(15),
	SR_MHZ(20),
	SR_MHZ(30),
	SR_MHZ(40),
	SR_MHZ(60),
	SR_MHZ(80),
	SR_MHZ(100),
	SR_MHZ(120),
	SR_MHZ(150),
	SR_MHZ(200),
	SR_MHZ(240),
};

static const int32_t trigger_matches[] =
{
  SR_TRIGGER_ZERO,
  SR_TRIGGER_ONE,
  SR_TRIGGER_RISING,
  SR_TRIGGER_FALLING,
  SR_TRIGGER_DEGE,
};


static const uint32_t drvopts[] =
{
  SR_CONF_OSCILLOSCOPE,
  SR_CONF_LOGIC_ANALYZER,
};


static const uint32_t devopts[] =
{
  SR_CONF_LIMIT_SAMPLES | SR_CONF_GET | SR_CONF_SET | SR_CONF_LIST,
  SR_CONF_TRIGGER_MATCH | SR_CONF_LIST,
  SR_CONF_CAPTURE_RATIO | SR_CONF_GET | SR_CONF_SET,
  SR_CONF_SAMPLERATE | SR_CONF_GET | SR_CONF_SET | SR_CONF_LIST,
}



static const uint32_t scanopts[] =
{
  SR_CONF_CONN,
};

SR_PRIV const char *digital_channel_names[] =
{
  "D1","D1",
};

SR_PRIV const char *analog_channel_names[] =
{
  "A1","A2",
};


static GSList *scan(struct sr_dev_driver *di, GSList *options)
{}

static int dev_open(struct sr_dev_inst *sdi) {}

static int dev_close(struct sr_dev_inst *sdi) {}

static int dev_clear(const struct sr_dev_driver *di) {}

static int config_get(uint32_t key, GVariant **data,
                      const struct sr_dev_inst *sdi,
                      const struct sr_channel_group *cg) {}

static int config_set(uint32_t key, GVariant **data,
                      const struct sr_dev_inst *sdi,
                      const struct sr_channel_group *cg) {}

static int config_list(uint32 key, GVariant **data,
                       const struct sr_dev_inst *sdi,
                       const struct sr_channel_group *cg) {}

static int dev_acquisition_start(const struct sr_dev_inst *sdi) {}

static int dev_acquisition_stop(struct sr_dev_inst *sdi) {}


static struct sr_dev_driver kiwi_driver_info = {
  .name = "kiwi"
  .longname = "Kiwi Tools With Logic Analyzer"
  .api_version = 1,
  .init = std_init,
  .cleanup = std_cleanup,
  .scan = scan,
  .dev_list = std_dev_list,
  .dev_clear = dev_clear,
  .context = NULL,
};

SR_REGISTER_DEV_DRIVER(kiwi_driver_info);


