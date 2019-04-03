import Vue from 'vue';
import * as Bootstrap from 'bootstrap-umi';
import 'bootstrap-umi/dist/css/bootstrap.css';

Vue.use(Bootstrap);

import Header from '../components/layouts/Header.vue';
import Router from '../router/index.js';

import { Application } from 'stimulus';
import { definitionsFromContext } from 'stimulus/webpack-helpers';

const application = Application.start();
const context = require.context('./controllers', true, /\.js$/);
application.load(definitionsFromContext(context));

const app = new Vue({
    el: '.app',
    router: Router,
    components: {
        'nav-bar': Header
    }
})