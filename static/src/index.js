import Vue from 'vue';
import * as Bootstrap from 'bootstrap-umi';
import 'bootstrap-umi/dist/css/bootstrap.css';

const app = new Vue({
    el: '.app',
    data: function() {
        return {
            message: 'Hello C++ Web Development Environment!'
        }
    }
})