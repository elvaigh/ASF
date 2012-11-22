
#ifndef _ADC_H_INCLUDED_
#define _ADC_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief ADC reference voltage enum.
 *
 * Enum for the possible reference voltages for the ADC
 *
 */
enum adc_reference {
	/** 1.0V voltage reference */
	ADC_REFERENCE_INT1V   = ADC_REF_INT1V_bm,
	/** 1/1.48 VCC reference */
	ADC_REFERENCE_INTVCC0 = ADC_REF_INTVCC0_bm,
	/** 1/2 VCC (only for internal Vcc > 2.1v) */
	ADC_REFERENCE_INTVCC1 = ADC_REF_INTVCC1_bm,
	/** External reference */
	ADC_REFERENCE_AREFA   = ADC_REF_AREFA_bm,
	/** External reference */
	ADC_REFERENCE_AREFB   = ADC_REF_AREFB_bm,
}

/**
 * \brief ADC clock prescaler enum.
 *
 * Enum for the possible clock prescaler values for the ADC
 *
 */
enum adc_clock_prescaler {
	/** ADC clock division factor 4 */
	ADC_CLOCK_PRESCALER_DIV4   = ADC_PRESCALER_DIV4_bm,
	/** ADC clock division factor 8 */
	ADC_CLOCK_PRESCALER_DIV8   = ADC_PRESCALER_DIV8_bm,
	/** ADC clock division factor 16 */
	ADC_CLOCK_PRESCALER_DIV16  = ADC_PRESCALER_DIV16_bm,
	/** ADC clock division factor 32 */
	ADC_CLOCK_PRESCALER_DIV32  = ADC_PRESCALER_DIV32_bm,
	/** ADC clock division factor 64 */
	ADC_CLOCK_PRESCALER_DIV64  = ADC_PRESCALER_DIV64_bm,
	/** ADC clock division factor 128 */
	ADC_CLOCK_PRESCALER_DIV128 = ADC_PRESCALER_DIV128_bm,
	/** ADC clock division factor 256 */
	ADC_CLOCK_PRESCALER_DIV256 = ADC_PRESCALER_DIV256_bm,
	/** ADC clock division factor 512 */
	ADC_CLOCK_PRESCALER_DIV512 = ADC_PRESCALER_DIV512_bm,
}

/**
 * \brief ADC resolution enum.
 *
 * Enum for the possible resolution values for the ADC
 *
 */
enum adc_resolution {
	/** ADC 12-bit resolution */
	ADC_RESOLUTION_12BIT = ADC_RESOLUTION_12BIT_bm,
	/** I assume this will be renamed in the datasheet. Supposed to be "averaging mode output" */
	ADC_RESOLUTION_16BIT = ADC_RESOLUTION_16BIT_bm,
	/** ADC 10-bit resolution */
	ADC_RESOLUTION_10BIT = ADC_RESOLUTION_10BIT_bm,
	/** ADC 8-bit resolution */
	ADC_RESOLUTION_8BIT = ADC_RESOLUTION_8BIT_bm,
}

/**
 * \brief ADC window monitor mode enum.
 *
 * Enum for the possible window monitor modes for the ADC
 *
 */
enum adc_window_mode {
	/** No window mode */
	ADC_WINDOW_DISABLE = ADC_WINMODE_DISABLE_bm,
	/** Mode 1: RESULT > WINLT */
	ADC_WINDOW_MODE_1 = ADC_WINMODE1_bm,
	/** Mode 2: RESULT < WINUT */
	ADC_WINDOW_MODE_2 = ADC_WINMODE2_bm,
	/** Mode 3: WINLT < RESULT < WINUT */
	ADC_WINDOW_MODE_3 = ADC_WINMODE3_bm,
	/** Mode 4: !( WINLT < RESULT < WINUT ) */
	ADC_WINDOW_MODE_4 = ADC_WINMODE4_bm,
}

/**
 * \brief ADC gain factor selection enum.
 *
 * Enum for the possible gain factor values for the ADC
 *
 */
enum adc_gain_factor {
	/** 1x gain */
	ADC_GAIN_FACTOR_1 = ADC_GAIN_1X_bm,
	/** 2x gain */
	ADC_GAIN_FACTOR_2 = ADC_GAIN_2X_bm,
	/** 4x gain */
	ADC_GAIN_FACTOR_4 = ADC_GAIN_4X_bm,
	/** 8x gain */
	ADC_GAIN_FACTOR_8 = ADC_GAIN_8X_bm,
	/** 16x gain */
	ADC_GAIN_FACTOR_16 = ADC_GAIN_16X_bm,
	/** 1/2x gain */
	ADC_GAIN_FACTOR_DIV2 = ADC_GAIN_DIV2_bm,
}

/**
 * \brief ADC positive MUX input selection enum.
 *
 * Enum for the possible positive MUC input selections for the ADC
 *
 */
enum adc_positive_input {
	/** ADC0 pin */
	ADC_POSITIVE_INPUT_PIN0          = ADC_POSPIN0_bm,
	/** ADC1 pin */
	ADC_POSITIVE_INPUT_PIN1          = ADC_POSPIN1_bm,
	/** ADC2 pin */
	ADC_POSITIVE_INPUT_PIN2          = ADC_POSPIN2_bm,
	/** ADC3 pin */
	ADC_POSITIVE_INPUT_PIN3          = ADC_POSPIN3_bm,
	/** ADC4 pin */
	ADC_POSITIVE_INPUT_PIN4          = ADC_POSPIN4_bm,
	/** ADC5 pin */
	ADC_POSITIVE_INPUT_PIN5          = ADC_POSPIN5_bm,
	/** ADC6 pin */
	ADC_POSITIVE_INPUT_PIN6          = ADC_POSPIN6_bm,
	/** ADC7 pin */
	ADC_POSITIVE_INPUT_PIN7          = ADC_POSPIN7_bm,
	/** ADC8 pin */
	ADC_POSITIVE_INPUT_PIN8          = ADC_POSPIN8_bm,
	/** ADC9 pin */
	ADC_POSITIVE_INPUT_PIN9          = ADC_POSPIN9_bm,
	/** ADC10 pin */
	ADC_POSITIVE_INPUT_PIN10         = ADC_POSPIN10_bm,
	/** ADC11 pin */
	ADC_POSITIVE_INPUT_PIN11         = ADC_POSPIN11_bm,
	/** ADC12 pin */
	ADC_POSITIVE_INPUT_PIN12         = ADC_POSPIN12_bm,
	/** ADC13 pin */
	ADC_POSITIVE_INPUT_PIN13         = ADC_POSPIN13_bm,
	/** ADC14 pin */
	ADC_POSITIVE_INPUT_PIN14         = ADC_POSPIN14_bm,
	/** ADC15 pin */
	ADC_POSITIVE_INPUT_PIN15         = ADC_POSPIN15_bm,
	/** ADC16 pin */
	ADC_POSITIVE_INPUT_PIN16         = ADC_POSPIN16_bm,
	/** ADC17 pin */
	ADC_POSITIVE_INPUT_PIN17         = ADC_POSPIN17_bm,
	/** ADC18 pin */
	ADC_POSITIVE_INPUT_PIN18         = ADC_POSPIN18_bm,
	/** ADC19 pin */
	ADC_POSITIVE_INPUT_PIN19         = ADC_POSPIN19_bm,
	/** ADC20 pin */
	ADC_POSITIVE_INPUT_PIN20         = ADC_POSPIN20_bm,
	/** ADC21 pin */
	ADC_POSITIVE_INPUT_PIN21         = ADC_POSPIN21_bm,
	/** ADC22 pin */
	ADC_POSITIVE_INPUT_PIN22         = ADC_POSPIN22_bm,
	/** ADC23 pin */
	ADC_POSITIVE_INPUT_PIN23         = ADC_POSPIN23_bm,
	/** Temperature reference */
	ADC_POSITIVE_INPUT_TEMP          = ADC_POSPIN_TEMP_bm,
	/** Bandgap voltage */
	ADC_POSITIVE_INPUT_BANDGAP       = ADC_POSPIN_BANDGAP_bm,
	/** 1/4 scaled core supply */
	ADC_POSITIVE_INPUT_SCALEDCOREVCC = ADC_POSPIN_SCALEDCOREVCC_bm,
	/** 1/4 scaled I/O supply */
	ADC_POSITIVE_INPUT_SCALEDIOVCC   = ADC_POSPIN_SCALEDIOVCC_bm,
	/** AUX input */
	ADC_POSITIVE_INPUT_AUX           = ADC_POSPIN_AUX_bm,
};

/**
 * \brief ADC negative MUX input selection enum.
 *
 * Enum for the possible negative MUC input selections for the ADC
 *
 */
enum adc_negative_input {
	/** ADC0 pin */
	ADC_NEGATIVE_INPUT_PIN0                        = ADC_NEGPIN0_bm,
	/** ADC1 pin */
	ADC_NEGATIVE_INPUT_PIN1                        = ADC_NEGPIN1_bm,
	/** ADC2 pin */
	ADC_NEGATIVE_INPUT_PIN2                        = ADC_NEGPIN2_bm,
	/** ADC3 pin */
	ADC_NEGATIVE_INPUT_PIN3                        = ADC_NEGPIN3_bm,
	/** ADC4 pin */
	ADC_NEGATIVE_INPUT_PIN4                        = ADC_NEGPIN4_bm,
	/** ADC5 pin */
	ADC_NEGATIVE_INPUT_PIN5                        = ADC_NEGPIN5_bm,
	/** ADC6 pin */
	ADC_NEGATIVE_INPUT_PIN6                        = ADC_NEGPIN6_bm,
	/** ADC7 pin */
	ADC_NEGATIVE_INPUT_PIN7                        = ADC_NEGPIN7_bm,
	/** ADC8 pin */
	ADC_NEGATIVE_INPUT_PIN8                        = ADC_NEGPIN8_bm,
	/** ADC9 pin */
	ADC_NEGATIVE_INPUT_PIN9                        = ADC_NEGPIN9_bm,
	/** ADC10 pin */
	ADC_NEGATIVE_INPUT_PIN10                       = ADC_NEGPIN10_bm,
	/** ADC11 pin */
	ADC_NEGATIVE_INPUT_PIN11                       = ADC_NEGPIN11_bm,
	/** ADC12 pin */
	ADC_NEGATIVE_INPUT_PIN12                       = ADC_NEGPIN12_bm,
	/** ADC13 pin */
	ADC_NEGATIVE_INPUT_PIN13                       = ADC_NEGPIN13_bm,
	/** ADC14 pin */
	ADC_NEGATIVE_INPUT_PIN14                       = ADC_NEGPIN14_bm,
	/** ADC15 pin */
	ADC_NEGATIVE_INPUT_PIN15                       = ADC_NEGPIN15_bm,
	/** ADC16 pin */
	ADC_NEGATIVE_INPUT_PIN16                       = ADC_NEGPIN16_bm,
	/** ADC17 pin */
	ADC_NEGATIVE_INPUT_PIN17                       = ADC_NEGPIN17_bm,
	/** ADC18 pin */
	ADC_NEGATIVE_INPUT_PIN18                       = ADC_NEGPIN18_bm,
	/** ADC19 pin */
	ADC_NEGATIVE_INPUT_PIN19                       = ADC_NEGPIN19_bm,
	/** ADC20 pin */
	ADC_NEGATIVE_INPUT_PIN20                       = ADC_NEGPIN20_bm,
	/** ADC21 pin */
	ADC_NEGATIVE_INPUT_PIN21                       = ADC_NEGPIN21_bm,
	/** ADC22 pin */
	ADC_NEGATIVE_INPUT_PIN22                       = ADC_NEGPIN22_bm,
	/** ADC23 pin */
	ADC_NEGATIVE_INPUT_PIN23                       = ADC_NEGPIN23_bm,
	/** Internal ground */
	ADC_NEGATIVE_INPUT_GND                         = ADC_NEGPIN_GND_bm,
	/** I/O ground */
	ADC_NEGATIVE_INPUT_IOGND                       = ADC_NEGPIN_IOGND_bm,
};

/**
 * \brief ADC averaging selection enum.
 *
 * Enum for the possible numbers of ADC samples to average
 *
 */
enum adc_average_samples {
	/** No averaging */
	ADC_AVERAGE_NONE         = ADC_SAMPLENUM1_bm,
	/** Average 2 samples */
	ADC_AVERAGE_SAMPLES_2    = ADC_SAMPLENUM2_bm,
	/** Average 4 samples */
	ADC_AVERAGE_SAMPLES_4    = ADC_SAMPLENUM4_bm,
	/** Average 8 samples */
	ADC_AVERAGE_SAMPLES_8    = ADC_SAMPLENUM8_bm,
	/** Average 16 samples */
	ADC_AVERAGE_SAMPLES_16   = ADC_SAMPLENUM16_bm,
	/** Average 32 samples */
	ADC_AVERAGE_SAMPLES_32   = ADC_SAMPLENUM32_bm,
	/** Average 64 samples */
	ADC_AVERAGE_SAMPLES_64   = ADC_SAMPLENUM64_bm,
	/** Average 128 samples */
	ADC_AVERAGE_SAMPLES_128  = ADC_SAMPLENUM128_bm,
	/** Average 265 samples */
	ADC_AVERAGE_SAMPLES_265  = ADC_SAMPLENUM265_bm,
	/** Average 512 samples */
	ADC_AVERAGE_SAMPLES_512  = ADC_SAMPLENUM512_bm,
	/** Average 1024 samples */
	ADC_AVERAGE_SAMPLES_1024 = ADC_SAMPLENUM1024_bm,
}

/**
 * \brief ADC oversamling and decimation enum.
 *
 * Enum for the possible numbers of bits you can increase resolution of
 * by using oversampling and decimation mode.
 *
 */
enum adc_oversampling_and_decimation {
	/** Don't use oversampling and decimation mode */
	ADC_OVERSAMPLING_AND_DECIMATION_DISABLE = 0,
	/** 1 bit resolution increase */
	ADC_OVERSAMPLING_AND_DECIMATION_1BIT,
	/** 2 bits resolution increase */
	ADC_OVERSAMPLING_AND_DECIMATION_2BIT,
	/** 3 bits resolution increase */
	ADC_OVERSAMPLING_AND_DECIMATION_3BIT,
	/** 4 bits resolution increase */
	ADC_OVERSAMPLING_AND_DECIMATION_4BIT
}

/**
 * \brief ADC configuration structure.
 *
 * Configuration structure for a ADC instance. This structure should be
 * initialized by the \ref adc_get_config_defaults()
 * function before being modified by the user application.
 */
struct adc_config {
	/** Voltage reference */
	enum adc_reference       reference;
	/** Clock prescaler */
	enum adc_clock_prescaler clock_prescaler;
	/** Result resolution */
	enum adc_resolution      resolution;
	/** Selected window mode */
	enum adc_window_mode     window_mode;
	/** Lower window value */
	int16_t                  window_lower_value;
	/** Upper window value */
	int16_t                  window_upper_value;
	/** Gain factor */
	enum adc_gain_factor     gain_factor;
	/** Positive MUX input */
	enum adc_positive_input  positive_input;
	/** Negative MUX input */
	enum adc_negative_input  negative_input;
	/** Average sampling mode */
	enum adc_average_samples average_samples;
	/** Oversampling and decimation mode */
	enum adc_oversampling_and_decimation oversampling_and_decimation;
	/** Left adjusted result */
	bool left_adjust;
	/** Differential mode */
	bool differential_mode;
	/** Free running mode */
	bool freerunning;
	/** Enable event input to trigger conversion start */
	bool start_conversion_on_event;
	/** Enable event input to trigger flush ADC module */
	bool flush_adc_on_event;
	/** Enable event generation on conversion done */
	bool generate_event_on_conversion_done;
	/** Enable event generation on window monitor */
	bool generate_event_on_window_monitor;
	/** ADC enabled in sleep mode */
	bool sleep_enable;
	/**
	Reference buffer offset compensation enable.
	Set this to true to ebable the reference buffer compensation to
	increase the accuracy of the gain stage. But decrease the input
	impedance; therefore increase the startup time of the reference.
	*/
	bool reference_compenstation_enable;
	/**
	Correct for gain and offset based on values of gain_correction amd
	offset_correction.
	*/
	bool correction_enable;
	/**
	If correction_enable is set to true, this value define how the ADC
	conversion result is compensated for gain error before written to
	the result register. This is a fractional value, 1-bit integer +
	11-bits fraction, therefore 1/2 <= gain_correction < 2.
	gain_correction values ranges from 0.10000000000 to 1.11111111111.
	*/
	uint16_t gain_correction;
	/**
	If correction_enable is set to true, these bits define how the ADC
	conversion result is compensated for offset error before written to
	the result register. This value is in two’s complement format.
	*/
	uint16_t offset_correction;
	/**
	This value (0-63) control the ADC sampling time in number of half ADC
	prescaled clock cycles (depends of ADC_PRESCALER value), thus
	controlling the ADC input impedance.
	Sampling time is set according to the formula:
	Sample time = (sample_length+1) * (ADCclk / 2)
	*/
	uint8_t sample_length;
};

/**
 * \brief ADC device instance structure.
 * ADC software instance structure.
 *
 */
struct adc_dev_inst {
	/** ADC hardware module */
	ADC_t *dev_ptr;
};

/**
 * \brief Wait for synchronization to finish
 *
 * Blocks in a busy wait while module synchronizes
 *
 * \param hw_dev pointer to hardware module
 */
static inline void _adc_wait_for_sync(ADC_t *const hw_dev)
{
	while (hw_dev->STATUS & ADC_STATUS_SYNCBUSY_bm) {
	}
}

/**
 * \brief Initializes the ADC module
 *
 * Initializes the ADC module, based on the values of the config struct
 *
 * \param dev_inst    pointer to the device struct
 * \param config pointer to the config struct
 */
status_code_t adc_init(struct adc_dev_inst *const dev_inst, ADC_t *hw_dev,
		struct adc_config *config);

/**
 * \brief Reset the ADC module
 *
 * \param[in] dev_inst Pointer to the ADC software instance struct
 */
static inline void adc_reset(struct adc_dev_inst *const dev_inst)
{
	/* Sanity check arguments */
	Assert(dev_inst);
	Assert(dev_inst->hw_dev);

	ADC_t *const adc_module = dev_inst->hw_dev;

	/* Always disable before reset */
	adc_disable(dev_inst);

	/* Software reset the module */
	_adc_wait_for_sync(module);
	adc_module->CTRLA |= ADC_SWRST_bm;
}

/**
 * \brief Initializes a ADC configuration structure to defaults
 *
 *  Initializes a given ADC configuration structure to a set of
 *  known default values. This function should be called on any new
 *  instance of the configuration structures before being modified by the
 *  user application.
 *
 *  The default configuration is as follows:
 *   \li 1V from internal bandgap reference
 *   \li Div 4 clock prescaler
 *   \li 12 bit resolution
 *   \li Window monitor disabled
 *   \li No gain
 *   \li Averaging disabled
 *   \li Oversampling disabled
 *   \li Right adjust data
 *   \li Single-ended mode
 *   \li Free running disabled
 *   \li All events (input and generation) disabled
 *   \li Sleep operation disabled
 *   \li No reference compensation
 *   \li No gain/offset correction
 *   \li No added sampling time
 *
 * \param[out] config  Configuration structure to initialize to default values
 */
static inline void adc_get_config_defaults(struct adc_config *const config)
{
	Assert(config);

	config->reference = ADC_REFERENCE_INT1V;
	config->clock_prescaler = ADC_CLOCK_PRESCALER_DIV4;
	config->resolution = ADC_RESOLUTION_12BIT;
	config->window_mode = ADC_WINDOW_DISABLE;
	config->adc_gain_factor = ADC_GAIN_FACTOR_1;
	config->average_samples = ADC_AVERAGE_DISABLE;
	config->oversampling_and_decimation =
			ADC_OVERSAMPLING_AND_DECIMATION_DISABLE;
	config->window_lower_value = 0;
	config->window_upper_value = 0;
	config->left_adjusted = false;
	config->differential_mode = false;
	config->freerunning = false;
	config->start_conversion_on_event = false;
	config->flush_adc_on_event = false;
	config->generate_event_on_conversion_done = false;
	config->generate_event_on_window_monitor = false;
	config->sleep_enable = false;
	config->reference_compenstation_enable = false;
	config->correction_enable = false;
	config->gain_correction = 0;
	config->offset_correction = 0;
	config->sample_length = 0;
}

/**
 * \brief Enable the ADC module
 *
 * Enables the ADC module.
 *
 * \param dev_inst    pointer to the device struct
 */
static inline void adc_enable(struct adc_dev_inst *const dev_inst)
{
	Assert(dev_inst);
	Assert(dev_inst->dev_ptr);

	ADC_t *const module = dev_inst->dev_ptr;

	_adc_wait_for_sync(module);
	module->CTRLA |= ADC_ENABLE_bm;
}

/**
 * \brief Disables the ADC module
 *
 * Disables the ADC module. Writes only prescaler to register.
 *
 * \param dev_inst    pointer to the device struct
 */
static inline void adc_disable(struct adc_dev_inst *const dev_inst)
{
	Assert(dev_inst);
	Assert(dev_inst->dev_ptr);

	ADC_t *const module = dev_inst->dev_ptr;

	_adc_wait_for_sync(module);
	module->CTRLA &= ~ADC_ENABLE_bm;
}

/**
 * \brief Flush the ADC pipeline
 *
 * Restart the ADC clock on the next peripheral clock edge.
 * All conversions in progress will be lost.
 * When flush is complete, the module will resume where it left off.
 *
 * \param dev_inst    pointer to the device struct
 */
static inline void adc_flush(struct adc_dev_inst *const dev_inst)
{
	Assert(dev_inst);
	Assert(dev_inst->dev_ptr);

	ADC_t *const module = dev_inst->dev_ptr;

	_adc_wait_for_sync(module);
	module->SWTRIG |= ADC_FLUSH_bm;

	/* Wait for flush to complete */
	while (module->SWTRIG & ADC_FLUSH_bm);
}

/**
 * \brief Start ADC conversion
 *
 * Starts an ADC conversion
 *
 * \param dev_inst      pointer to the device struct
 */
static inline void adc_start_conversion(struct adc_dev_inst *const dev_inst)
{
	Assert(dev_inst);
	Assert(dev_inst->dev_ptr);

	ADC_t *const module = dev_inst->dev_ptr;

	_adc_wait_for_sync(module);
	module->SWTRIG |= ADC_START_bm;
}

/**
 * \brief Read ADC result
 *
 * Read result from ADC conversion. Clears INTFLAG register after reading.
 *
 * \param dev_inst       pointer to device struct
 * \param result         pointer to store result
 */
static inline status_code_t adc_get_result(struct adc_dev_inst *const dev_inst, uint16_t *result)
{
	Assert(dev_inst);
	Assert(dev_inst->dev_ptr);
	Assert(result);

	if (!adc_is_result_ready(dev_inst)) {
		/* Result not ready. Abort. */
		return STATUS_ERR_BUSY;
	}

	ADC_t *const module = dev_inst->dev_ptr;

	_adc_wait_for_sync(module);
	/* Get ADC result */
	*result = module->RESULT;
	/* Reset ready flag */
	module->INTFLAG = ADC_RESRDY_bm;

	return STATUS_OK;
}

/**
 * \brief Check if result is ready in ADC
 *
 * Check wether a new result is ready in result register
 *
 * \param dev_inst       pointer to device struct
 */
static inline bool adc_is_result_ready(struct adc_dev_inst *const dev_inst)
{
	Assert(dev_inst);
	Assert(dev_inst->dev_ptr);

	ADC_t *const module = dev_inst->dev_ptr;

	return module->INTFLAG & ADC_RESRDY_bm;
}

/**
 * \brief Check if window monitor flag is set in ADC
 *
 * Check wether the window monitor interrupt flag is set.
 *
 * \param dev_inst       pointer to device struct
 */
static inline bool adc_is_window_flag_set(struct adc_dev_inst *const dev_inst)
{
	Assert(dev_inst);
	Assert(dev_inst->dev_ptr);

	ADC_t *const module = dev_inst->dev_ptr;

	return module->INTFLAG & ADC_WINMON_bm;
}

/**
 * \brief Reset the ADC window monitor flag
 *
  * \param dev_inst       pointer to device struct
 */
static inline void adc_reset_window_flag(struct adc_dev_inst *const dev_inst)
{
	Assert(dev_inst);
	Assert(dev_inst->dev_ptr);

	ADC_t *const module = dev_inst->dev_ptr;

	module->INTFLAG = ADC_WINMON_bm;
}

/**
 * \brief Change ADC window mode
 *
 * Initializes the ADC module, based on the values of the config struct
 *
 * \param dev_inst           pointer to the device struct
 * \param adc_window_mode    window monitor mode to set
 * \param window_lower_value lower window monitor threshold value
 * \param window_upper_value upper window monitor threshold value
  */
static inline void adc_set_window_mode(struct adc_dev_inst *const dev_inst,
		enum adc_window_mode window_moe,
		int16_t              window_lower_value,
		int16_t              window_upper_value)
{
	/* Sanity check arguments */
	Assert(dev_inst);
	Assert(dev_inst->hw_dev);

	ADC_t *const adc_module = dev_inst->hw_dev;

	_adc_wait_for_sync(hw_dev);
	hw_dev->WINCTRL = window_mode        << ADC_WINMODE_bp;
	_adc_wait_for_sync(hw_dev);
	hw_dev->WINLT   = window_lower_value << ADC_WINLT_bp;
	_adc_wait_for_sync(hw_dev);
	hw_dev->WINUT   = window_upper_value << ADC_WINUT_bp;
}


#ifdef __cplusplus
}
#endif

#endif /* _ADC_H_INCLUDED_ */
