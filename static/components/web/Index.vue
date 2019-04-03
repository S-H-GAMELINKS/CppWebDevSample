<template>
    <div>
        <h1>Index Pages</h1>
        <p>Let's Enjoy C++/Vue.js/Stimulus Realtime Chat!<p>
            
        <div class="container" data-controller="chat" data-chat-url="/api/talks" data-chat-refresh-interval="100">
            <div class="input-group">
                <div class="input-group-append">
                    <span class="input-group-text">Input Tlack</span>
                </div>
                <input type="text" class="form-control" data-target="chat.content"> 
            </div>
            <p>
                <button type="button" class="btn btn-primary" data-action="click->chat#submit">Submit</button>
            </p>
            <div data-target="chat.talks"></div>
        </div>
    </div>    
</template>
