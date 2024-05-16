__connectorSpec = {
    'mikrobus': {
        'an': 1, 
        'rst':2, 
        'spi': {
            'cs': 3, 
            'sck':4, 
            'miso': 5, 
            'mosi': 6
        }, 
        'pwm': 16, 
        'int': 15, 
        'uart': {
            'tx': 13, 
            'rx': 14,
        }, 
        'i2c': {
            'sda': 11, 
            'scl': 12
        }
    },
    'xplainpro': {
        'adc plus': 3,
        'adc minus': 4,
        'gpio1': 5,
        'gpio2': 6,
        'pwm plus': 7,
        'pwm minus': 8,
        'irq': 9,
        'gpio ss': 10,
        'spi': {
            'cs': 15,
            'sck': 18,
            'miso': 17,
            'mosi': 16
        }, 
        'uart': {
            'tx': 14,
            'rx': 13,
        }, 
        'i2c': {
            'sda': 11,
            'scl': 12,
        }
    }
}

def getConnectorPinNumberFromSignal(connectorCompatible, **kwargs):
    # print("CHRIS dbg: getPinNumberFromConnectorSpec", connector, kwargs)
    connectorPins = __connectorSpec.get(connectorCompatible)
    if connectorPins != None:
        signalGroup = kwargs.get('signalGroup')
        signalPin = kwargs.get('signalPin')
        # print("CHRIS dbg: getPinNumberFromConnectorSpec {} {}".format(signalGroup, signalPin))
        if (signalGroup != None):
            pinNumber = __connectorSpec.get(connectorCompatible).get(signalGroup).get(signalPin)
        else:
            pinNumber = __connectorSpec.get(connectorCompatible).get(signalPin)
    else:
        pinNumber = None

    return pinNumber

def getConnectorSignalMapMikroBUSXplainPro():
    # Signal Map : {mikroBus, XplainPro}
    signalMap = {}
    signalMap.setdefault('an', 'adc plus')
    signalMap.setdefault('rst', 'gpio1')
    signalMap.setdefault('pwm', 'pwm plus')
    signalMap.setdefault('int', 'irq')

    return signalMap