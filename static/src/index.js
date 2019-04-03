import Vue from 'vue';
import * as Bootstrap from 'bootstrap-umi';
import 'bootstrap-umi/dist/css/bootstrap.css';

Vue.use(Bootstrap);

import Header from '../components/layouts/Header.vue';

const app = new Vue({
    el: '.app',
    components: {
        'nav-bar': Header
    },
    data: function() {
        return {
            message: 'Hello C++ Web Development Environment!'
        }
    }
})