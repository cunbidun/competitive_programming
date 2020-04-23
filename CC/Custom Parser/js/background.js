/******/ (function(modules) { // webpackBootstrap
/******/ 	// The module cache
/******/ 	var installedModules = {};
/******/
/******/ 	// The require function
/******/ 	function __webpack_require__(moduleId) {
/******/
/******/ 		// Check if module is in cache
/******/ 		if(installedModules[moduleId]) {
/******/ 			return installedModules[moduleId].exports;
/******/ 		}
/******/ 		// Create a new module (and put it into the cache)
/******/ 		var module = installedModules[moduleId] = {
/******/ 			i: moduleId,
/******/ 			l: false,
/******/ 			exports: {}
/******/ 		};
/******/
/******/ 		// Execute the module function
/******/ 		modules[moduleId].call(module.exports, module, module.exports, __webpack_require__);
/******/
/******/ 		// Flag the module as loaded
/******/ 		module.l = true;
/******/
/******/ 		// Return the exports of the module
/******/ 		return module.exports;
/******/ 	}
/******/
/******/
/******/ 	// expose the modules object (__webpack_modules__)
/******/ 	__webpack_require__.m = modules;
/******/
/******/ 	// expose the module cache
/******/ 	__webpack_require__.c = installedModules;
/******/
/******/ 	// define getter function for harmony exports
/******/ 	__webpack_require__.d = function(exports, name, getter) {
/******/ 		if(!__webpack_require__.o(exports, name)) {
/******/ 			Object.defineProperty(exports, name, { enumerable: true, get: getter });
/******/ 		}
/******/ 	};
/******/
/******/ 	// define __esModule on exports
/******/ 	__webpack_require__.r = function(exports) {
/******/ 		if(typeof Symbol !== 'undefined' && Symbol.toStringTag) {
/******/ 			Object.defineProperty(exports, Symbol.toStringTag, { value: 'Module' });
/******/ 		}
/******/ 		Object.defineProperty(exports, '__esModule', { value: true });
/******/ 	};
/******/
/******/ 	// create a fake namespace object
/******/ 	// mode & 1: value is a module id, require it
/******/ 	// mode & 2: merge all properties of value into the ns
/******/ 	// mode & 4: return value when already ns object
/******/ 	// mode & 8|1: behave like require
/******/ 	__webpack_require__.t = function(value, mode) {
/******/ 		if(mode & 1) value = __webpack_require__(value);
/******/ 		if(mode & 8) return value;
/******/ 		if((mode & 4) && typeof value === 'object' && value && value.__esModule) return value;
/******/ 		var ns = Object.create(null);
/******/ 		__webpack_require__.r(ns);
/******/ 		Object.defineProperty(ns, 'default', { enumerable: true, value: value });
/******/ 		if(mode & 2 && typeof value != 'string') for(var key in value) __webpack_require__.d(ns, key, function(key) { return value[key]; }.bind(null, key));
/******/ 		return ns;
/******/ 	};
/******/
/******/ 	// getDefaultExport function for compatibility with non-harmony modules
/******/ 	__webpack_require__.n = function(module) {
/******/ 		var getter = module && module.__esModule ?
/******/ 			function getDefault() { return module['default']; } :
/******/ 			function getModuleExports() { return module; };
/******/ 		__webpack_require__.d(getter, 'a', getter);
/******/ 		return getter;
/******/ 	};
/******/
/******/ 	// Object.prototype.hasOwnProperty.call
/******/ 	__webpack_require__.o = function(object, property) { return Object.prototype.hasOwnProperty.call(object, property); };
/******/
/******/ 	// __webpack_public_path__
/******/ 	__webpack_require__.p = "";
/******/
/******/
/******/ 	// Load entry module and return exports
/******/ 	return __webpack_require__(__webpack_require__.s = 33);
/******/ })
/************************************************************************/
/******/ ({

/***/ 33:
/***/ (function(module, exports, __webpack_require__) {

"use strict";

var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : new P(function (resolve) { resolve(result.value); }).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
Object.defineProperty(exports, "__esModule", { value: true });
const hosts_1 = __webpack_require__(34);
const messaging_1 = __webpack_require__(7);
const messaging_2 = __webpack_require__(8);
function checkTab(tabId, changeInfo, tab) {
    messaging_2.sendToContent(tabId, messaging_1.MessageAction.CheckTab, {
        tabId,
        url: tab.url,
    });
}
function handleHistoryStateUpdate(details) {
    const { tabId, url } = details;
    messaging_2.sendToContent(tabId, messaging_1.MessageAction.CheckTab, {
        tabId,
        url,
    });
}
function parse(tab) {
    messaging_2.sendToContent(tab.id, messaging_1.MessageAction.Parse);
}
function send(tabId, message) {
    hosts_1.getHosts().then((hosts) => __awaiter(this, void 0, void 0, function* () {
        for (const host of hosts) {
            try {
                yield host.send(message);
            }
            catch (err) {
                //
            }
        }
        messaging_2.sendToContent(tabId, messaging_1.MessageAction.TaskSent);
    }));
}
function handleMessage(message, sender) {
    if (!sender.tab) {
        return;
    }
    switch (message.action) {
        case messaging_1.MessageAction.EnablePageAction:
            browser.pageAction.show(sender.tab.id);
            break;
        case messaging_1.MessageAction.DisablePageAction:
            browser.pageAction.hide(sender.tab.id);
            break;
        case messaging_1.MessageAction.SendTask:
            send(sender.tab.id, message.payload.message);
            break;
    }
}
browser.tabs.onUpdated.addListener(checkTab);
browser.webNavigation.onHistoryStateUpdated.addListener(handleHistoryStateUpdate);
browser.pageAction.onClicked.addListener(parse);
browser.runtime.onMessage.addListener(handleMessage);


/***/ }),

/***/ 34:
/***/ (function(module, exports, __webpack_require__) {

"use strict";

var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : new P(function (resolve) { resolve(result.value); }).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
Object.defineProperty(exports, "__esModule", { value: true });
const config_1 = __webpack_require__(4);
const CHelperHost_1 = __webpack_require__(35);
const CustomHost_1 = __webpack_require__(36);
const defaultHosts = [new CHelperHost_1.CHelperHost()];
const defaultPorts = [
    4244,
    6174,
    10042,
    10043,
];
function getHosts() {
    return __awaiter(this, void 0, void 0, function* () {
        const customPorts = yield config_1.config.get('customPorts');
        const uniquePorts = [...new Set(defaultPorts.concat(customPorts))];
        return defaultHosts.concat(uniquePorts.map(port => new CustomHost_1.CustomHost(port)));
    });
}
exports.getHosts = getHosts;


/***/ }),

/***/ 35:
/***/ (function(module, exports, __webpack_require__) {

"use strict";

Object.defineProperty(exports, "__esModule", { value: true });
class CHelperHost {
    send(data) {
        return new Promise(resolve => {
            const xhr = new XMLHttpRequest();
            xhr.open('POST', 'http://localhost:4243/', true);
            xhr.timeout = 500;
            xhr.onload = () => resolve();
            xhr.ontimeout = () => resolve();
            xhr.onabort = () => resolve();
            xhr.onerror = () => resolve();
            try {
                xhr.send('json\n' + data);
                xhr.send();
            }
            catch (err) {
                //
            }
        });
    }
}
exports.CHelperHost = CHelperHost;


/***/ }),

/***/ 36:
/***/ (function(module, exports, __webpack_require__) {

"use strict";

Object.defineProperty(exports, "__esModule", { value: true });
class CustomHost {
    constructor(port) {
        this.port = port;
    }
    send(data) {
        return new Promise(resolve => {
            const xhr = new XMLHttpRequest();
            xhr.open('POST', `http://localhost:${this.port}`, true);
            xhr.setRequestHeader('Content-Type', 'application/json');
            xhr.timeout = 500;
            xhr.onload = () => resolve();
            xhr.ontimeout = () => resolve();
            xhr.onabort = () => resolve();
            xhr.onerror = () => resolve();
            try {
                xhr.send(data);
                xhr.send();
            }
            catch (err) {
                //
            }
        });
    }
}
exports.CustomHost = CustomHost;


/***/ }),

/***/ 4:
/***/ (function(module, exports, __webpack_require__) {

"use strict";

var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : new P(function (resolve) { resolve(result.value); }).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
Object.defineProperty(exports, "__esModule", { value: true });
class Config {
    constructor() {
        this.defaultValues = {
            customPorts: [],
            debugMode: false,
        };
    }
    get(key) {
        return __awaiter(this, void 0, void 0, function* () {
            const data = yield browser.storage.local.get(key);
            return data[key] || this.defaultValues[key];
        });
    }
    set(key, value) {
        return browser.storage.local.set({ [key]: value });
    }
}
exports.config = new Config();


/***/ }),

/***/ 5:
/***/ (function(module, exports, __webpack_require__) {

"use strict";

Object.defineProperty(exports, "__esModule", { value: true });
function noop() {
    // Do nothing
}
exports.noop = noop;


/***/ }),

/***/ 7:
/***/ (function(module, exports, __webpack_require__) {

"use strict";

Object.defineProperty(exports, "__esModule", { value: true });
var MessageAction;
(function (MessageAction) {
    MessageAction[MessageAction["CheckTab"] = 0] = "CheckTab";
    MessageAction[MessageAction["Parse"] = 1] = "Parse";
    MessageAction[MessageAction["EnablePageAction"] = 2] = "EnablePageAction";
    MessageAction[MessageAction["DisablePageAction"] = 3] = "DisablePageAction";
    MessageAction[MessageAction["SendTask"] = 4] = "SendTask";
    MessageAction[MessageAction["TaskSent"] = 5] = "TaskSent";
})(MessageAction = exports.MessageAction || (exports.MessageAction = {}));


/***/ }),

/***/ 8:
/***/ (function(module, exports, __webpack_require__) {

"use strict";

Object.defineProperty(exports, "__esModule", { value: true });
const noop_1 = __webpack_require__(5);
function sendToBackground(action, payload = {}) {
    browser.runtime
        .sendMessage({ action, payload })
        .then(noop_1.noop)
        .catch(noop_1.noop);
}
exports.sendToBackground = sendToBackground;
function sendToContent(tabId, action, payload = {}) {
    browser.tabs
        .sendMessage(tabId, { action, payload })
        .then(noop_1.noop)
        .catch(noop_1.noop);
}
exports.sendToContent = sendToContent;


/***/ })

/******/ });